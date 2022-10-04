#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,countr=0,countc=0;
    cin>>n>>m;
    vector<string> v;
    for(int i=0; i<n; i++){
        int flag=0;
        string s;
        cin>>s;
        v.push_back(s);
        for(int j=0; j<m; j++){
            if(s[j]=='S'){
                flag=1;
                break;
            }
        }
        if(flag==0){
            countr++;
        }
    }
    for(int i=0; i<m; i++){
        int flag=0;
        for(int j=0; j<n; j++){
            if(v[j][i]=='S'){
                flag=1;
            }
        }
        if(flag==0){
            countc++;
        }
    }
    cout<<(countr*m)+(n-countr)*countc<<"\n";
}
