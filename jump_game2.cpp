class Solution {
public:
    int jump(vector<int>& nums) {

        if (nums.size() == 1) return 0;

        int count = 1;
        int limit = nums[0];
        int i = 1;
        while(limit < nums.size() - 1){
            int newlimit = limit;
            while(i <= limit){
                newlimit = max(i + nums[i], newlimit);
                i++;
            }
            limit = newlimit;
            count ++;
        }
        return count;
    }

};
