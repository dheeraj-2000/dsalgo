#include<bits/stdc++.h>
using namespace std;

int binary_to_decimal(int n){
    int ans=0;
    int x =1;
    while(n>0){
        int y = n%10;
        ans+=x*y;
        x *= 2;
        n /= 10;
    }
    return ans;
}

int octal_to_decimal(int n){
    int ans=0;
    int x =1;
    while(n>0){
        int y = n%10;
        ans+=x*y;
        x *= 8;
        n /= 10;
    }
    return ans;
}



int hexadecimal_to_decimal(string n){
    int ans=0;
    int x =1;
    int s = n.size();
    for(int i=s-1;i>=0;i++){
        if(n[i]>='0' && n[i]<='9')
        {
            ans += x*(n[i]-'o');
        }
        else if(n[i] >= 'A' && n[i] <='F'){
            ans += x*(n[i]-'A'+10);
        }
        x *=16;
    }
    return ans;
    // while(n>0){
    //     int y = n%10;
    //     ans+=x*y;
    //     x *= 16;
    //     n /= 10;
    // }
    // return ans;
}

int decimaltobinary(int n){
    int x =1;
    int ans =0;
    while(x<=n){
        x *=2
    }
    x/=2;
    while(x>0){
        int lastdigit =n/x;
        n -= lastdigit*x;
        x/=2;
        ans =ans*10 +lastdigit;
    }
    return ans;
}

int32_t main(){
    int n;
    string n;
    cin>>n;

    cout<<binarytodecimal(n)<<endl;
    cout<<binarytodecimal(n)<<endl;
    cout<<deciamltobianry(n)<<endl;
}