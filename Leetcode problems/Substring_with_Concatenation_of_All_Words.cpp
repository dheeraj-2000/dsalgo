class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n=words.size();
        int m=words[0].length();
        unordered_map<string, int> mp;
        for(auto it : words){
            mp[it]++;
        }
        if(m*n>s.length()){
            return ans;
        }
        for(int i=0;i<=s.length()-(m*n);i++){
            unordered_map<string,int> temp=mp;
            bool pos=false;
            for(int j=0;j<n;j++){
                int dis=i+(j*m);
                string curr=s.substr(dis, m);
                if(temp.find(curr)!=temp.end()){
                    if(j==n-1){
                        pos=true;
                    }
                    temp[curr]--;
                    if(temp[curr]==0){
                        temp.erase(curr);
                    }
                }else{
                    break;
                }
            }
            if(pos){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
