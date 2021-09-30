// problem: https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    /**
     * for every number in the array:
     *  - if there was a number previously k-diff with it, save the smaller to a set;
     *  - and save the value-index to a map;
     */
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_set<int> starters;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i] - k)) {
                starters.insert(nums[i] - k);
            }
            if (indices.count(nums[i] + k)) {
                starters.insert(nums[i]);
            }

            indices[nums[i]] += 1;
        }
        
        return starters.size();
    }
};