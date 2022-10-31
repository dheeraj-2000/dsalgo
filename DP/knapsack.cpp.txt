#include <bits/stdc++.h>

using namespace std;
int solve(int n,int W,int wt[],int v[])
{
    int i,j,t[n+1][W+1];
    for(i=0;i<n+1;i++)
        for(j=0;j<W+1;j++)
    {
        if(i==0||j==0)
            t[i][j]=0;
    }
    for(i=1;i<n+1;i++)
        for(j=1;j<W+1;j++)
    {
    if(wt[i-1]<=j)
    {
        t[i][j]=max(v[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
    }
    else if(wt[i-1]>j)
    {
        t[i][j]=t[i-1][j];
    }
    }
    return t[n][W];
}

int main()
{
    int i,n,W,wt[1000],val[1000];
    cin>>n>>W;
    for(i=0;i<n;i++)
        cin>>wt[i];
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<solve(n,W,wt,val)<<endl;
}
