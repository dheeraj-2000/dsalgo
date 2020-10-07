//Graph representation using adjacency lists (Alternative:adjacency matrix)
//Iterative Deepening Depth First Search or IDDFS is a mix of BFS and DFS. BFS uses more memory and DFS isn't optimal, so to overcome these issues
//we use IDDFS. In IDDFS we perform DFS upto a certain depth and keep incrmenting it gradually until we find the goal. To perform this we use 
//Depth-Limited Search or DLS.(It performs DFS upto a certain limit)
//Time Complexity: O(b^d) where b is branching factor and d is maximum depth
//Space Complexity: O(b*d)
//The following algorithm tells whether a path exists or not between source node and goal node
#include<iostream>
#include<list>
#include<stack>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
class Graph
{
    int v;                              //no. of vertices
    list<int> *adjlist;                 //pointer to array containing adjacency lists
    public:
    Graph(int value)
    {
        v = value;
        adjlist= new list<int>[value];
    }
    //function to add an edge between two vertices of undirected graph
    void AddEdge(int u, int v)
    {
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    //Depth Limited search performs dfs only upto a certain depth limit
    bool DLS(int source, int goal, int limit)
    {
        if(source==goal)                                //it returns true if it finds the goal
            return true;
        if(limit <= 0)                                  //it returns false if we reach the end of our limit
            return false;
        for (auto it = adjlist[source].begin(); it!=adjlist[source].end(); it++)        //we recursively traverse all vertices adjacent to source
        {
            if (DLS(*it, goal, limit-1))
                return true;
        }
        return false;
    }
    bool IDDFS(int source, int goal, int max_limit)
    {
        for(int i=0; i<=max_limit; i++)                                 //DLS is repeated for all depths till max depth is reached
        {
            if (DLS(source, goal, i))
                return true;
        }
        return false;
    }
};
int main()
{
    auto start = high_resolution_clock::now();
    Graph g(8);
    g.AddEdge(0,5);
    g.AddEdge(5,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(2,4);
    g.AddEdge(0,1);
    g.AddEdge(1,6);
    g.AddEdge(1,7);
    if (g.IDDFS(0,4,4)==true)
        cout << "A path exists" << endl;
    else
        cout << "No path exists" << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Execution Time: " << duration.count()<<" ms"<< endl;
    return 0;
}