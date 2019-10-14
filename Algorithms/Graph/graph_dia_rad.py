import sys 

class Graph(): 
  
    def __init__(self, vertices): 
        self.V = vertices 
        self.graph = [[0 for column in range(vertices)]  
                      for row in range(vertices)] 
  
    def printSolution(self, dist,i,m):
        
        for node in range(self.V):
            if(dist[node] >= m):
                m=dist[node]
        return m
  
    def minDistance(self, dist, sptSet): 
        min = sys.maxsize
  
        for v in range(self.V): 
            if dist[v] < min and sptSet[v] == False: 
                min = dist[v] 
                min_index = v 
  
        return min_index 

    def dijkstra(self, src,m): 
  
        dist = [sys.maxsize] * self.V 
        dist[src] = 0
        sptSet = [False] * self.V 
  
        for cout in range(self.V): 

            u = self.minDistance(dist, sptSet) 
            sptSet[u] = True
  
            for v in range(self.V): 
                if (self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]): 
                        dist[v] = dist[u] + self.graph[u][v] 
  
        return self.printSolution(dist,src,m) 

n=9
g  = Graph(n) 
g.graph = [[0, 1, 0, 0, 0, 0, 0, 1, 0], 
           [1, 0, 1, 0, 0, 0, 0, 1, 0], 
           [0, 1, 0, 1, 0, 1, 0, 0, 1], 
           [0, 0, 1, 0, 1, 1, 0, 0, 0], 
           [0, 0, 0, 1, 0, 1, 0, 0, 0], 
           [0, 0, 1, 1, 1, 0, 1, 0, 0], 
           [0, 0, 0, 0, 0, 1, 0, 1, 1], 
           [1, 1, 0, 0, 0, 0, 1, 0, 1], 
           [0, 0, 1, 0, 0, 0, 1, 1, 0] 
          ];
m=0
arr=[0]*9
for i in range(n):
    arr[i] = g.dijkstra(i,m);
print(arr)
print ("Diameter of graph is:",max(arr))
print ("Radius of graph is:",min(arr))