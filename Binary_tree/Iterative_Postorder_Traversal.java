import java.util.*;

class tree_Node {
    int data;
    tree_Node left;
    tree_Node right;

    tree_Node() {
    }

    tree_Node(int data) {
        this.data = data;
    }

    tree_Node(int data, tree_Node left, tree_Node right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

public class Iterative_PostOrder {
    static Scanner sc = null;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        tree_Node root = createTree();

        System.out.println(postorderTrav(root));
    }

    static tree_Node createTree() {
        tree_Node root = null;
        System.out.println("Enter data: ");
        int data = sc.nextInt();
        if (data == -1)
            return null;
        root = new tree_Node(data);
        System.out.println("Enter left for " + data);
        root.left = createTree();
        System.out.println("Enter right for " + data);
        root.right = createTree();

        return root;

    }

    public static List<Integer> postorderTrav(tree_Node root) {
        List<Integer> postorder = new ArrayList<Integer>();
        Stack<tree_Node> s = new Stack<tree_Node>();
        tree_Node cur = root;
        if (cur == null)
            return postorder;
        while (cur != null || !s.isEmpty()) {
            if (cur != null) {
                s.push(cur);
                cur = cur.left;
            } else {
                tree_Node temp = s.peek().right;
                if (temp == null) {
                    temp = s.peek();
                    s.pop();
                    postorder.add(temp.data);

                    while (!s.isEmpty() && temp == s.peek().right) {
                        temp = s.peek();
                        s.pop();
                        postorder.add(temp.data);
                    }
                } else
                    cur = temp;
            }
        }

        return postorder;
    }
}
// The worst case T.C is O(2*N) or O(N) and S.C is O(N)(Stack use)
// There is also a two stack approach of PostOrder traversal;
