#include<bits/stdc++.h>
using namespace std;
	#define author          "Sihare0riginals"
	#define ss       		string 
	#define lli      		long long int
	#define ld       		long double
	#define f        		first
	#define s        		second
	#define all(v)   		v.begin(),v.end()
	#define I(a,i)			memset(a,i,sizeof(a));
	#define pb       		push_back
	#define mp       		make_pair
	#define L(i,start,end)  for(lli i=start;i<=end;i++)
	#define R(i,start,end)  for(lli i=start;i>=end;i--)
	#define ip(n) 			cin>>n;lli ip[n+1];L(i,1,n)cin>>ip[i];
const lli LINF = 1e18,mod=1e9+7;
 
 
signed main()
{
	lli t=1;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli ip[n+1];
		L(i,1,n)
		cin>>ip[i];
		sort(ip+1,ip+n+1);
		lli DP[n+1][401];
		I(DP,-1);
		L(i,0,2*n)
		DP[0][i]=0;
		L(i,1,n)
		{
			L(j,1,2*n)
			{
				lli val=LINF;
				L(k,0,j-1)
				{
					if(DP[i-1][k]!=-1)
					{
						val=min(val,DP[i-1][k]);
					}
				}
				val+=abs(ip[i]-j);
				DP[i][j]=val;
			}
		}
		lli ans=LINF;
		L(i,1,2*n)
		ans=min(DP[n][i],ans);
		cout<<ans<<endl;
	}
	return 0;
}