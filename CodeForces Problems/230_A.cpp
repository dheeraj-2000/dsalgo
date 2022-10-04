#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int s,n,row=0,flag=0;
    cin>>s>>n;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        vector<int> drogon(2);
        for(auto &it:drogon){
            cin>>it;
        }
        v.push_back(drogon);
    }
    sort(v.begin(), v.end());
    while(s>v[row][0]){
        flag++;
        s+=v[row][1];
        if(row==n-1){
            break;
        }
        else{
            row++;
        }
    }
    if(row==n-1 && flag==n){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}