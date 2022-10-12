Depth First Search (DFS) for Graph

DFS-I: Given an undirected graph and a source vertex s, print DFS from the given source.**

I/P: s=0,       0
              /   \
             1     4
            /     / \
           2     5---6

O/P: 0, 1, 2, 4, 5, 6
Algorithm:
1. Create a recursive function that takes the index of node and a visited array.
2. Mark the current node as visited and print the node.
3. Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution{
public:
	void DFSUtil(int i, vector<int> adj[], int V, bool visited[], vector<int> &res){
	    if(visited[i]) return;
	    visited[i] = true;
	    res.push_back (i);
	    for (int j : adj[i]){
	        if (!visited[j])
	            DFSUtil(j, adj, V, visited, res);
	    }
	}
	
	vector<int> dfsOfGraph(int V, vector<int> adj[]){
	    bool visited[V];
	    memset(visited, false, sizeof(visited));
	
	    vector <int> res;
	    for (int i = 0; i < V; i++)
	        if (!visited[i]){
	            DFSUtil (i, adj, V, visited, res);
	        }
	    return res;
	}
};
