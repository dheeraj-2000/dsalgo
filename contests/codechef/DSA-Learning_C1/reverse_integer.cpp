#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t,num,result=0;
    cin>>t;
    while(t--){
        cin>>num;
        int result = 0;
            while(num !=0){
                  if (INT_MAX/10 < result) return 0;
                  if (INT_MIN/10 > result ) return 0;

                  result = result*10 + (num%10);
                  num = num/10;
            }
        cout<<result<<endl;
    }
    return 0;
}
