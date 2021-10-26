#include <bits/stdc++.h>

using namespace std;
int solve(int a[],int sum,int n)
{
    int i,j,t[n+1][sum+1];
    for(i=0;i<n+1;i++)
        for(j=0;j<sum+1;j++)
    {
        if(i==0)
            t[i][j]=0;
        if(j==0)
            t[i][j]=1;

    }
    for(i=1;i<n+1;i++)
        for(j=1;j<sum+1;j++)
    {
    if(a[i-1]<=j)
    {
        t[i][j]=(t[i-1][j-a[i-1]]||t[i-1][j]);
    }
    else if(a[i-1]>j)
    {
        t[i][j]=t[i-1][j];
    }
    }
    return t[n][sum];
}

int main()
{
    int n,i,a[10000],sum=0,p,z,m=999999;
    cin>>n;
    for(i=0;i<n;i++)
        {cin>>a[i];
        sum=sum+a[i];}
    //cin>>sum;
    for(i=0;i<=sum/2;i++)
    {

     p=solve(a,i,n);
     if(p==1)
      {

       //cout<<i<<endl;
    z=sum-(2*i);
    //cout<<z<<
    m=min(m,z);}

     }
     cout<<m<<endl;


    //cout<<p<<endl;
}
