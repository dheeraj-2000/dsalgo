#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        if(num == 0)
        cout<<1<<endl;
        else if(num == 1 || num == 2)
        cout<<2<<endl;
        else{
            int sum=1;
            while(2*sum <= num) 
            sum *= 2;
            if(sum== num)
            cout<<num<<endl;
            else if(num == (2*sum - 1))
            cout<<num+1<<endl;
            else
            cout<<sum<<endl;
        }




        // if(num == 0){
        //     cout<<1<<endl;
        //     continue;
        // }
        // else if(num == 1 || num == 2){
        //     cout<<2<<endl;
        //     continue;
        // }
        // else{
        //     int sum=1;
        //     while(2*sum <= num){
        //         sum *= 2;
        //     }
        //     if(sum== num){
        //         cout<<num<<endl;
        //     }
        //     else if(num == (2*sum - 1)){
        //         cout<<num-1<<endl;
        //     }
        //     else{
        //         cout<<sum<<endl;
        //     }
        // }
    }
}