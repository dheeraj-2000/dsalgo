public:
	vector<bool>vis;
	vector<int>v;
	
	void dfs(int i,vector<int>adj[]){
	    vis[i]=true;
	    for(auto j:adj[i]){
	        if(!vis[j])dfs(j,adj);
	    }
	    v.push_back(i);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vis.resize(V,false);
	    for(int i=0;i<V;++i){
	        if(!vis[i])dfs(i,adj);
	    }
	    
	    
	    reverse(v.begin(),v.end());
	    return v;
	}
