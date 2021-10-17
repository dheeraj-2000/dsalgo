/*

Time Complexity- O(N)
Space complexity- O(N)

*/
#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1) return nums[0];

        if(n==2) return max(nums[0],nums[1]);

        if(n==3) return max({nums[0],nums[1],nums[2]});
           //Since you can't rob 1st and last house together as well as as any two adjacent houses

        //Case 1: Start robbing from house 0 and end at house n-2
        vector<int> dp1(n-1,0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);

        for(int i=2;i<n-1;i++) dp1[i] = max(dp1[i-2]+nums[i],dp1[i-1]);

        //Case 2: Start robbing from house 1 and end at house n-1
        vector<int> dp2(n-1,0);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1],nums[2]);

        for(int i=2;i<n-1;i++) dp2[i] = max(dp2[i-2]+nums[i+1],dp2[i-1]);


//Return the max of the two cases
return max(dp1[n-2],dp2[n-2]);
    }

int main()
{
    int n;
    cout << "Enter the number of houses\n";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the amount of money in each house\n";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << rob(nums) << endl;
    return 0;
}

