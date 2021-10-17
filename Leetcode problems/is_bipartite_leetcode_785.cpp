/*
Leetcode: 785
Link: https://leetcode.com/problems/is-graph-bipartite/

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <functional>
#include <queue>

using namespace std;

bool isBipartiteCheck(vector<vector<int>>& graph, int src, vector<int> &vis)
{
    queue<int> que;
    que.push(src);
    int color = 0;
    bool isCycle = false;
    while(que.size() != 0)
    {
        int size = que.size();
        while(size-->0)
        {
            int rvtx = que.front();
            que.pop();
            if(vis[rvtx] != -1)
            {
                isCycle = true;
                if(vis[rvtx] != color)
                    return false;
                continue;
            }
            vis[rvtx] = color;
            for(int v : graph[rvtx])
            {
                if(vis[v] == -1)
                    que.push(v);
            }
        }
        color = (color+1)%2;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n,-1);
    bool res = true;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
            res = res && isBipartiteCheck(graph, i, vis);
    }

    return res;
}

int main()
{
	vector<vector<int>> graph{{1,2,3},{0,2},{0,1,3},{0,2}};
	bool Bipartite = isBipartite(graph);

	if (Bipartite)
		cout<<"The given graph is Bipartite.";
	else
		cout<<"The given graph is NOT Bipartite.";

	return 0;
}