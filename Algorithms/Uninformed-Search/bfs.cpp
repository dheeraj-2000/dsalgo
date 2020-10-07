//Graph representation using adjacency lists (Alternative:adjacency matrix)
//Breadth First Search or BFS is a searching algorithm that starts at the source and traverses all neighbours at one level before moving on to the next one
//Time Complexity: O(V+E) where V= |vertices| and E=|Edges| for implementation using adjacency lists
//Space Complexity: O(V)
//Completeness : Yes
//Optimality: Yes, as long as edge costs remain equal.
//The following algorithm gives a path from source node to goal node
#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<chrono>
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
    //predecessor[] stores the predecessor of a vertex
    bool BFS(int source, int goal, int predecessor[])
    {
        bool visited[v];                            //tells whether vertices have already been visited or not
        for (int i=0; i<v; i++)
        {
            visited[i]=false;                       //initially no vertex is visited
            predecessor[i]=-1;                      //predecessor of every vertex is initialised to -1
        }
            
        queue<int> q;                               //queue stores the vertices whose adjacent vertices are to be checked(FIFO)
        visited[source] = true;                     //the source node is now visited
        q.push(source);
        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            source = q.front();                     //extract the first vertex in the queue
            q.pop();                                //pop the vertex from queue and check it's adjacency list
            cout << source << " ";
            for (auto it = adjlist[source].begin(); it!=adjlist[source].end(); it++)            //it is used to iterate over the adjacency list
            {
                
                if (visited[*it]==false)               //if a vertex hasn't been visited yet, we visit it and add it to the back of the queue
                {
                    visited[*it] = true;
                    predecessor[*it] = source;
                    q.push(*it);
                    if (*it == goal)
                    {
                        cout << goal;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //function to print the path
    void PrintPath(int source, int goal)
    {
        int predecessor[v];
        
        if (BFS(source, goal, predecessor) == false)
        {
            cout << "\nNo path exists" << endl;
            return;
        }
        vector<int> path;                           //this vector stores all the nodes that we find after backtracking the path from the goal
        int backtrack = goal;                   
        path.push_back(backtrack);
        while(predecessor[backtrack]!=-1)
        {
            path.push_back(predecessor[backtrack]);
            backtrack = predecessor[backtrack];
        }
        cout <<"\nPath: ";
        for(int i = path.size()-1; i>-1; i--)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
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
    g.PrintPath(0,4);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Execution Time: " << duration.count()<<" ms"<< endl;
    return 0;
}