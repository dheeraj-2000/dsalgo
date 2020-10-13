/*
Bipartite graph is a GRaph in which if a node is in one set then the child node should be in other set.
it does not contain cycle.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int > adj[1005];
vector<int > vis(1005);
vector<int > col(1005);
bool bipartite(int u,int c){
    vis[u]=1;
    col[u]=c;
    for(auto i : adj[u]){
        if(vis[i]==0){
            if(bipartite(i,c^1)==false){
                return false;
            }
        }else{
            if(col[u]==col[i]){
                return false;
            }
        }
    }
    return true;
}
int main() {
    
    int n,e,x,y,c=1;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    if(bipartite(1,1)){
        for(int i=1;i<=6;i++){
            cout<<col[i]<<" ";
        }
        cout<<"its a bipartite graph"<<endl;
    }
    else{
        cout<<"its not a bipartite graph"<<endl;
    }
}
