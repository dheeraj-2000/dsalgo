#include<bits/stdc++.h>         // Accepted
using namespace std;

void solve(vector<int>& nums, int ind, vector<int> op, int sum, int t) {

    if(sum > t) return;  // We should not move further if sum > target sum

    if(ind == nums.size()) {
        if(sum == t) {
            for(auto i : op) cout<<i<<", ";
            cout<<"."<<"\n";
        }
        return;
    }

    vector<int> op1 = op;
    op1.push_back(nums[ind]);
    solve(nums, ind+1, op1, sum+nums[ind],t);
    solve(nums, ind+1, op, sum,t);


}


int main() {
    int n,t;
    cin>>n;

    vector<int> nums(n);
    for(auto& i : nums) cin >> i;

    cin>>t;

    vector<int> op;

    solve(nums,0,op,0,t);

    return 0;
}