#include<bits/stdc++.h>
using namespace std;

// Our own function taking an array and its size as parameters
int getMissingNumber(int a[], int n){
    int i, total;
    
    total= ((n+1)*(n+2))/2;
    for(i=0; i<n; i++){
        total-=a[i];
    }
    return total;
}

// Main Function
int main(){
    
    int a[] = {1,3,4,8,10};
    int n= sizeof(a)/sizeof(a[0]);
    
    cout<<"Missing number is: "<<getMissingNumber(a,n);
    return 0;
}
