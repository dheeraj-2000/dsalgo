/* Problem Statement
1.You are given a graph.
2. You are required to find and print if the graph is cyclic.

Sample Input
7
6
0 1 10
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10

Sample Output
false


Approach:
The solution we are going to discuss in this article uses Breadth First Search (BFS) Algorithm.
What does it mean, when we say that there is a cycle present in the graph?
It means that there exists a pair of vertices (u, v) such that there is not an unique path from node u to node v. 
In simple words, there exists at least two different paths of reaching node v from the node u.

img
To find if there exists such two paths, we can do a BFS traversal of the given graph. 
For every visited vertex "v", we will push all the neighbouring vertices "u" into the queue.
Now, here is the crux of the algorithm. If the neighboring vertex is already visited, then there exists at least two different paths from node v to node u. 
It is because we were able to visit the vertex u, as it must have been popped out from the queue earlier.
Now, since there exists two different paths from node v to node u, there is a cycle present in the graph, (and nodes u and v must be part of that cycle).

Q) Can you figure out a problem here? (HINT: Graph is undirected, i.e. edges are bidirectional) ?

Since the graph is undirected, it means there will be edge u to v, as well as edge v to u. 
Hence, node u will be present in the adjacency list of node v and similarly vice-versa.
Once we will find the neighbours of node v, then we will get node u as a neighbour which is already visited. 
We will report that there is a cycle present, but the bidirectional edge does not mean a cycle.
Thus, we should also maintain the information of the parent node, and not consider the parent node as the neighbour of the child node.
We use a parent array to keep track of the parent vertex for a vertex so that we do not consider the visited parent as a cycle.
Q) Will the algorithm work if we start the BFS from any one node, let us suppose node 0?

We are given in the problem statement that the graph may or may not be connected. Hence, we will have to check whether there exists a cycle in any component of the graph.
To check cycles in all components, we will start BFS from each unvisited node in [0, n-1], and report true if there exists a cycle in any component.
Note: If you get this problem in a face-to-face interview, then you must ask about the corner cases like:
Q)Can there be edges of type (u, u), i.e. does self loops exist in the graph ?
Q) Can there be multiple parallel edges, i.e. does there exist more than 1 edge (u, v) in the graph ?
For simplicity, we can assume that there are no self loops and parallel edges in the current problem.
*/

import java.io.*;
import java.util.*;

public class Main {
   static class Edge {
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph[v1].add(new Edge(v1, v2, wt));
         graph[v2].add(new Edge(v2, v1, wt));
      }

      // write your code here
      LinkedList<Integer>queue = new LinkedList<>();
      int[]par = new int[vtces];
      Arrays.fill(par,-1);
      
      for(int i=0; i<vtces;i++)
      {
          if(par[i]!= -1)
          {
              continue;
          }
          queue.addLast(i);
          par[i]= -3;
          
          while(queue.size()>0)
          {
              int rem = queue.removeFirst();
              
              for(Edge tempnbr: graph[rem])
              {
                  if(par[tempnbr.nbr]== -1)
                  {
                      queue.addLast(tempnbr.nbr);
                      par[tempnbr.nbr] = rem;
                  }
                  else
                  {
                      if(tempnbr.nbr != par[rem])
                      {
                          System.out.println(true);
                          return;
                      }
                  }
              }
          }
      }
      System.out.println(false);
      
   }
}
