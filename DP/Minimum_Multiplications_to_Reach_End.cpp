/*Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 
is done to get the new start.
Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.*/

int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int> distance(1e6,INT_MAX);
        distance[start] = 0;
        int mod = 1e5;
        
        while(!q.empty()){
            
            auto top = q.front();
            q.pop();
            
            int currNode = top.second;
            int currDist = top.first;
            
            for(int i=0;i<arr.size();i++){
                int newNode = (currNode*arr[i])%mod;
                if(distance[newNode]>currDist+1){
                    q.push({currDist+1,newNode});
                    distance[newNode] = currDist+1;
                }
            }
            
        }
        
        return distance[end]==INT_MAX?-1:distance[end];
    }
