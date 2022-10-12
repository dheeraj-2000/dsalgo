I/P: s=0,         1-----3
                 /       \
                0---------5
                 \       /
                  2-----4

O/P: 0, 1, 2, 5, 3, 4
Algorithm:
1. Use a boolean list to mark all the vertices as not visited.
2. Initially mark first vertex as visited(true).
3. Create a queue for BFS and push first vertex in queue.
4. While queue is not empty:
   I. Keep adding front element in output list and popping it from queue.
   II. Traverse over all the connected components of front element.
   III. If they aren't visited, mark them visited and add to queue.
5. Return the output list.
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
public:
  	vector<int> bfsOfGraph(int V, vector<int> adj[]){
	    vector<bool> visited(V, false);
	    int s = 0;
	    visited[s] = true; 
	    vector<int> res;
	    queue<int> q;
	    q.push(s);
	    while (!q.empty()) {
	        int t = q.front();
	        res.push_back(t);
	        q.pop();
	        for(int v : adj[t])
	            if(!visited[v]){ 
	                visited[v] = true;
	                q.push(v);
	            }
	    }
	    return res;
  	}
};
