#include<bits/stdc++.h>
using namespace std;

// topological sorting along with cycle detection
void dfs(vector<int> adj[],int vis[],stack<int>& order,int cur){
    vis[cur]=1;
    for(int nbr:adj[cur]){
        if(vis[nbr]==0){
            dfs(adj,vis,order,nbr);
        }else{
            // if we found cycle it means impossible
            if(vis[nbr]==1){
                cout<<"IMPOSSIBLE";
                exit(0);
            }
        }
    }
    order.push(cur);
    vis[cur]=2;
}

void solve(){
    int n,m;
    cin>>n>>m;

    // adjacency list
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    // finding the topo sort
    int vis[n+1]={0};
    stack<int> order;
    for(int i=1;i<n+1;i++){
        if(vis[i]==0){
            dfs(adj,vis,order,i);
        }
    }

    while(order.size()){
        cout<<order.top()<<" ";
        order.pop();
    }
}
int main(){
    solve();
    return 0;
}