#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int new_n=n,rem,ans=0,c=0;
        // if(n/d == 1){
        //     cout<<1<<endl;
        //     continue;
        // }
        while(new_n>0){
            rem=new_n%10;
            new_n=new_n/10;
            c++;
            if(rem==d){
                new_n=new_n*pow(10,c)+(rem+1)*pow(10,c-1);
                ans=new_n-n;
                c=0;
            }
        }
        cout<<ans<<endl;
    }
}