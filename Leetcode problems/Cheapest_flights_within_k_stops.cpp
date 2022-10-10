// Problem link:https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Using bellman-ford algorithm

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int e=flights.size();
        vector<int> prev;
        prev.assign(n,INT_MAX);
        prev[src]=0;
        k++;//k now represents path length
        
        for(int i=1;i<=k;i++){
            bool anyUpdate=false;
            vector<int> cur;
            cur=prev;
            for(int j=0;j<e;j++){
                int u=flights[j][0];
                int v=flights[j][1];
                int wt=flights[j][2];
                
                if(prev[u]==INT_MAX){
                    continue;
                }
                
                //path with i path length => getting updated at exactly ith iteration(since we are comparing from prev)
                if(prev[u]+wt<cur[v]){
                    anyUpdate=true;
                    cur[v]=prev[u]+wt;
                }
            }
            prev=cur;
            if(!anyUpdate){
                break;
            }
        }
        
        if(prev[dst]==INT_MAX){
            return -1;
        }
        return prev[dst];
    }
};