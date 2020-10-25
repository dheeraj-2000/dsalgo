
//3. Longest Substring Without Repeating Characters
//Link-https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string st)
    {
        unordered_set<char> s;
        int c = 0;
        int maxx = 1;
        if (st == "")
            return 0;
        if (st == " ")
            return 1;
        for (int i = 0; i < st.length(); i++)
        {
            if (s.find(st[i]) == s.end())
            {
                s.insert(st[i]);
                c++;
                maxx = max(maxx, c);
            }
            else
            {

                i = i - c;
                c = 0;
                s.clear();
            }
        }
        return maxx;
    }
};