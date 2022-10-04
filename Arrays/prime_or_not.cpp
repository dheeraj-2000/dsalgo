#include<iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int c=2;
    for(int i=2;i<=n;i++){
        if(i% n/2 == 0){// we sort search by half n or sqrt(n func in header math header
            cout<<"\n Number is not prime";
            //break;
            return 1; //completely get out of main
            //what if we pass return;
        }
        c=i;
    }
    cout<<"Hello";
    if(c==n){
        cout<<"\nNumber is prime";
    }

}