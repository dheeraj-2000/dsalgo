#include <bits/stdc++.h>

using namespace std;
//int mod=10e9+7;
//typedef long long int
void solve(int x)
{
    long long int mod=10e8+7;
    //cout<<"mkidsf"<<mod<<endl;
    long long int i,j;
    vector<long long  int>count(x+1);
    count[0]=1;

    for(i=1;i<=x;i++)
    {
        count[i]=0;
        for(j=1;j<=6;j++)
        {
            //count[i]=count[i]%mod;
            if(i-j>=0)
            {

                count[i]=count[i]+count[i-j];
                count[i]=count[i]%mod;
            }
        }
        //cout<<count[i]<<endl;
    }
    cout<<count[x]<<endl;
   // cout<<count[x]%mod<<endl;

}


int main()
{
int x;
    cin>>x;
    solve(x);

}
