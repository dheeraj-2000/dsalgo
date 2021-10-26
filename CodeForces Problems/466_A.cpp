#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b,cost1,cost2;
    cin>>n>>m>>a>>b;
    if(b>(a*m)){
        cout<<n*a<<endl;
    }
    else{
        cost1=(n/m)*b+(n-(n/m)*m)*a;
        cost2=(n/m)*b+b;
        cout<<min(cost1,cost2)<<endl;
    }
    return 0;
}