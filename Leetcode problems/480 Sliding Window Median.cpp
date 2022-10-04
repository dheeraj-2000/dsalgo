//480 sliding window median problem of leetcode
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        if (k == 1)
            return vector<double>(nums.begin(), nums.end()); // To handle the case when k == 1, I dont know why this code is giving TLE on k == 1.

        multiset<long> s1, s2;
        vector<double> ans;
        int l = 0, r = 0;
        while (r < nums.size())
        {
            // Inserting and Balancing (Took this from here https://leetcode.com/problems/find-median-from-data-stream/))
            s1.insert(nums[r]);
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
            if (s2.size() > s1.size())
            {
                s1.insert(*s2.begin());
                s2.erase(s2.begin());
            }
            r++;
            if (r - l >= k) // Removing elements that are outside the window
            {
                if (k % 2 == 0)
                    ans.push_back((*s1.rbegin() + *s2.begin()) / 2.0);
                else
                    ans.push_back(*s1.rbegin());

                if (nums[l] >= *s2.begin())
                    s2.erase(s2.find(nums[l]));
                else
                    s1.erase(s1.find(nums[l]));
                l++;
            }
        }

        return ans;
    }
};