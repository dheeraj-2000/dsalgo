#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    vector<vector<int>> adj(n);
    vector<int> indegre(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegre[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegre[i] == 0){
            q.push(i);
        }

    }
    while(!q.empty()){
        cnt++;
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it: adj[x]){
            indegre[it]--;
            if(indegre[it] == 0){
                q.push(it);
            }
        }
    }
    return 0;
}

// contributed by Abhijeet Anand