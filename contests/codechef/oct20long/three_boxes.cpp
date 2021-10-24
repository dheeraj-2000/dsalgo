#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a,b,c,d;
    while(t--){
        cin>>a>>b>>c>>d;
        if(a+b+c<=d){
            cout<<1<<endl;
        }
        else if(a+c<=d){
            cout<<2<<endl;
        }
        else if(a+b<=d){
            cout<<2<<endl;
        }
        else if(b+c<=d){
            cout<<2<<endl;
        }
        else{
            cout<<3<<endl;
        }
        // if(float(a+b+c)/d > (a+b+c)/d){
        //     cout<<(a+b+c)/d +1<<endl;
        // }
        // else{
        //     cout<<(a+b+c)/d<<endl;
        // }
        
    }
}


    // cout<<(3+2+5)/10<<endl;
    // if(float(1+2+3)/5 > (1+2+3)/5){
    //     cout<<(1+2+3)/5 +1<<endl;
    // }
    // // cout<<(float(1+2+3)/5)<<endl;
    // cout<<(3+3+4)/4<<endl;