#include<bits/stdc++.h>
using namespace std;

struct Edge { 
  int src, dest, weight; 
}; 

struct Graph { 
  int V, E; 
  struct Edge* edge; 
}; 
  
struct Graph* createGraph(int V, int E) 
{ 
  struct Graph* graph = new Graph; 
  graph->V = V; 
  graph->E = E; 
  graph->edge = new Edge[E]; 
  return graph; 
} 

void showDist(int dist[], int n) 
{ 
  cout<<"Vertex Distance from Source"<<endl; 
  for (int i = 0; i < n; ++i) 
    cout<<i<<"  "<<dist[i]<<endl; 
} 

void bellmanFord(struct Graph* graph, int src){
  int V = graph->V; 
  int E = graph->E; 
  int dist[V];

  for (int i = 0; i < V; i++) 
    dist[i] = INT_MAX; 
  dist[src] = 0;

  for(int i=0;i<V-1;i++){
    for (int j = 0; j < E; j++){
      int u = graph->edge[j].src; 
      int v = graph->edge[j].dest; 
      int w = graph->edge[j].weight; 
      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
        dist[v] = dist[u] + w;
    }
  }

  for (int i = 0; i < E; i++) { 
    int u = graph->edge[i].src; 
    int v = graph->edge[i].dest; 
    int weight = graph->edge[i].weight; 
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
      cout<<"Graph contains negative weight cycle, hence the shortest distance is not gauranteed"<<endl; 
      return; 
    } 
  } 
  showDist(dist,V);
}

int main(){
  int n,m;
  cin>>n>>m;
  struct Graph* graph = createGraph(n, m);
    
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    graph->edge[i].src = u-1; 
    graph->edge[i].dest = v-1; 
    graph->edge[i].weight = w;
  }

  bellmanFord(graph,0);
  return 0;
}
