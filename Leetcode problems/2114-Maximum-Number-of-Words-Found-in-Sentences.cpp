class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;        //to store final answer
        
        for(auto &s : sentences) 
        {
            int cnt = 1;    //as numbers of words is 1 greater than number of spaces
            for(auto &c : s) 
            {
                if(c == ' ') 
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
