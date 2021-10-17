#include <bits/stdc++.h>
using namespace std;

bool ispal(string str){
    int s=0, e=str.length()-1;
    while(s<=e && str[s]==str[e]){
        s++; e--;
    }

    return s>=e;
}

void fun(string &s, int cuts, int &ans){
    if(s.length()==0){
        ans=min(ans,cuts);
        return;
    }
    for(int i=1; i<=s.length(); i++){
        string left=s.substr(0,i);
        string right=s.substr(i);
        if(ispal(left)){
            cuts++;
            fun(right, cuts, ans);
            cuts--;
        }
    }
}

int palindromicPartitioning(string str){
    int ans=INT_MAX;
    fun(str, -1, ans);
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<palindromicPartitioning(str)<<"\n";

    return 0;
}
