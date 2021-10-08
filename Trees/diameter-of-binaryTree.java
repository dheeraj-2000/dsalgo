/*Problem Statement: 
1. You are given a partially written BinaryTree class.
2. You are required to complete the body of diameter1 function. 
The function is expected to return the number of edges between two nodes which are farthest from each other in terms of edges.

Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n

Sample Output
6
*/

/*Approach :
-We need to maximize the number of edges between any two nodes to calculate diameter.
-To be noted that to maximize the number of edges we have to always consider the leaf nodes.
-Now we wish to find the diameter that passes through our current node.
-This can be found by adding the height of the deepest node in the left subtree and height of deepest node in right subtree and adding 2 to their sum.
-We call this as factor 1.
-But there is a possibility that a larger diameter is present entirely in either the left subtree or right subtree.
-Let's call factor 2 to be the diameter in the left subtree. So this represents the scenario when both the deepest nodes lie in the left subtree.
-And factor 3 is the diameter in the right subtree. This represents the scenario when both the deepest nodes lie in the right subtree.
-The final result will be the maximum of these three factors.
-Now we can recurse this approach for every node in our tree as our diameter does not always pass through the root node. So at each node, we calculate the diameter using all three factors and compare them and return the maximum value.
*/


import java.io.*;
import java.util.*;

public class Main {
  public static class Node {
    int data;
    Node left;
    Node right;

    Node(int data, Node left, Node right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }
  }

  public static class Pair {
    Node node;
    int state;

    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }

  public static Node construct(Integer[] arr) {
    Node root = new Node(arr[0], null, null);
    Pair rtp = new Pair(root, 1);

    Stack<Pair> st = new Stack<>();
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0) {
      Pair top = st.peek();
      if (top.state == 1) {
        idx++;
        if (arr[idx] != null) {
          top.node.left = new Node(arr[idx], null, null);
          Pair lp = new Pair(top.node.left, 1);
          st.push(lp);
        } else {
          top.node.left = null;
        }

        top.state++;
      } else if (top.state == 2) {
        idx++;
        if (arr[idx] != null) {
          top.node.right = new Node(arr[idx], null, null);
          Pair rp = new Pair(top.node.right, 1);
          st.push(rp);
        } else {
          top.node.right = null;
        }

        top.state++;
      } else {
        st.pop();
      }
    }

    return root;
  }

  public static void display(Node node) {
    if (node == null) {
      return;
    }

    String str = "";
    str += node.left == null ? "." : node.left.data + "";
    str += " <- " + node.data + " -> ";
    str += node.right == null ? "." : node.right.data + "";
    System.out.println(str);

    display(node.left);
    display(node.right);
  }

  public static int height(Node node) {
    if (node == null) {
      return -1;
    }

    int lh = height(node.left);
    int rh = height(node.right);

    int th = Math.max(lh, rh) + 1;
    return th;
  }
  // diameter func
  public static int diameter1(Node node) {
    if(node==null){
        return 0;
    }
    int ld = diameter1(node.left);
    int rd = diameter1(node.right);
    
    int f = height(node.left) + height(node.right)+2;
    int dia = Math.max(f,Math.max(ld,rd));
    return dia;
  }
  
  static class DiaPair{
      int dia;
      int ht;
      
  } 
  
  public static DiaPair diameter2(Node node){
      
      if(node==null){
          DiaPair bp = new DiaPair();
          bp.dia = 0;
          bp.ht = -1;
          
          return bp;
      }
      
      DiaPair lp = diameter2(node.left);
      DiaPair rp = diameter2(node.right);
      
      DiaPair mp = new DiaPair();
      mp.ht = Math.max(lp.ht,rp.ht)+1;
      
      int fes = lp.ht + rp.ht + 2;
      mp.dia = Math.max(fes,Math.max(lp.dia,rp.dia));
      
      return mp;
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Integer[] arr = new Integer[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      if (values[i].equals("n") == false) {
        arr[i] = Integer.parseInt(values[i]);
      } else {
        arr[i] = null;
      }
    }

    Node root = construct(arr);

    // int diameter = 0;
    // diameter = diameter1(root);
    // System.out.println(diameter);
    DiaPair p = diameter2(root);
    System.out.println(p.dia);
  }

}
