#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,count=0;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &it:v){
        cin>>it;
    }
    sort(v.begin(),v.end());
    if(n<3){
        cout<<0<<endl;
    }
    else{
        for(int i=2; i<n; i+=3){
            if(5-v[i]>=k){
                count++;
            }
        }
        cout<<count<<endl;
    }
    

    return 0;
}