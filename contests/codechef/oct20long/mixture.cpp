#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a,b;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a>0 && b>0){
            cout<<"Solution\n";
        }
        else if(a==0 && b>0){
            cout<<"Liquid\n";
        }
        else{
            cout<<"Solid\n";
        }

    }
    // while(t>0){
    //     int a,b;
    //     cin>>a>>b;
    //     if(a>0 && b>0){
    //         cout<<"Solution\n";
    //     }
    //     else if(a==0 && b>0){
    //         cout<<"Liquid\n";
    //     }
    //     else{
    //         cout<<"Solid\n";
    //     }
    // }
}