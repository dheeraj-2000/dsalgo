class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//       vector<int>vec;
//         for(int i=0;i<nums.size()-k+1;i++){
//             int maxi=*max_element(nums.begin()+i,nums.begin()+i+k);
            
//             vec.push_back(maxi);
//         }
        
//         return vec;
     //Solving using deque as TLE was coming in 49th test case;
//      vector<int>ans;
//      deque<int>win(k);
//     int i;
//      for(i=0;i<k;i++){
//          while(!win.empty() && nums[i]>=win.back()){
//              win.pop_back();
//          }
//          win.push_back(i);
//      }
//         for(auto i:win){
//             cout<<i;
//         }
//      for(;i<nums.size();i++){
//         ans.push_back(nums[win.front()]);
         
//         while(!win.empty() && win.front()<=i-k){
//             win.pop_front();
//         }
         
//          while(!win.empty() && nums[i]>=win.back()){
//              win.pop_back();
//          }
         
//          win.push_back(i);
//      }
        
//     ans.push_back(nums[win.front()]);
        
    
//      return ans;
        
        vector <int> ans;
        int n=nums.size();
        deque <int> q; 
        for(int i=0;i<n;i++)
        {   
            while(!q.empty() && i-q.front()>=k)
                q.pop_front();
            
            while(!q.empty() && nums[q.back()]<nums[i])
                q.pop_back();
            
            q.push_back(i);
            
            if(i>=k-1)ans.push_back(nums[q.front()]); 
        }
        
        return ans;
    }
};