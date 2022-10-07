class Solution {
public:
    int findSum(int num){
        int sum = 0;
        while(num){
            sum += (num % 10);
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<int> sumOfNums;
        for(int i: nums){
            sumOfNums.push_back(findSum(i));
        }
        int maxi = -1;
        unordered_map<int, int> um;
        for(int i=0; i<sumOfNums.size(); ++i){
            if(um.find(sumOfNums[i]) != um.end()){
                int sum = um[sumOfNums[i]] + nums[i];
                maxi = max(maxi, sum);
                um[sumOfNums[i]] = max(um[sumOfNums[i]], nums[i]);
            } else {
                um[sumOfNums[i]] = nums[i];
            }
        }
        return maxi;
    }
};