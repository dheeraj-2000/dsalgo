/*
	Author:- Akash
	
	problem:- You are given a primitive calculator that can perform the following three operations with
	the current number x: multiply x by 2, multiply x by 3, or add 1 to x. Your goal is given a
	positive integer n, find the minimum number of operations needed to obtain the number n
	starting from the number 1.
	
	Output format: -output the minimum number k of operations needed to get n from 1.
					In the second line output a sequence of intermediate numbers. That is, the second line should contain
					positive integers a0, a2, . . . , an-1 such that a0 = 1, ak-1 = n and for all 0 = i < k - 1, ai+1 is equal to
					either ai+1, 2ai, or 3ai.
					. If there are many such sequences, output any one of them.
	
	Input:
		96234
	Output:
			14
			1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234

*/
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007LL
#define mod 998244253LL
#define ll long long int
#define all(p) p.begin(),p.end()
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}



int main() {
	//clock_t t=clock();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,INF=100000000,ans,i,j;
	cin>>n;
	
	int dp[n+1];
	
	for(i=0;i<=n;i++)
		dp[i]=INF;
		
	dp[1]=0;
	
	for(i=2;i<=n;i++)
	{
		ans=INF;
		if(i%3==0)
			ans=min(ans,dp[i/3]);
			
		if(i%2==0)
			ans=min(ans,dp[i/2]);
			
		if(i-1>=1)
			ans=min(ans,dp[i-1]);
		
		dp[i]=ans+1;
	}
	cout<<dp[n]<<endl;
	int a[dp[n]];
	i=n,j=0;
	while(1)
	{
		int p=INF,q=INF,r=INF,min1;
		if(i%3==0) 
			p=dp[i/3];
			
		if(i%2==0) 
			q=dp[i/2];
			
		if(i-1>=1) 
			r=dp[i-1];
			
		min1=min(min(p,q),r);
		
		if(min1==p) 
			i/=3;
			
		else if(min1==q)
			 i/=2;
			 
		else if(min1==r) 
			i-=1;
			
		if(i<1)
			break;
			
		a[j++]=i;
	}
	
	for(i=j-1;i>=0;i--) 
		cout<<a[i]<<" ";
	cout<<n;
	
	return 0;
}

