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
	while(t--){
		lli n,m,k;
		cin>>n>>m>>k;
		lli ip[n+1][m+1];
		L(i,1,n)
		{
			L(j,1,m)
				cin>>ip[i][j];
		}
		lli DP[n+1][m+1][m+1][k];
		I(DP,-1);
		
		L(i,1,n)
		{
			L(j,0,m/2)
			DP[i][0][j][0]=0;
			L(j,1,m)
			{
				DP[i][j][0][0]=0;
				lli rem=ip[i][j]%k;
				L(l,1,m/2)				//no of elements
				{
					L(o,0,k-1)			//remainder
					{
						lli req=(k-rem+o)%k;
						if(DP[i][j-1][l-1][req]!=-1)
						DP[i][j][l][o]=max(DP[i][j][l][o],DP[i][j-1][l-1][req]+ip[i][j]);
						if(DP[i][j-1][l][o]!=-1)
						DP[i][j][l][o]=max(DP[i][j][l][o],DP[i][j-1][l][o]);
					}
				}
			}
		}
		lli OP[n+1][k];
		lli val[n+1][k];
		I(val,-1);
		L(i,1,n)
		{
			L(j,0,k-1)
			{
				L(l,0,m/2)
				{
					L(a,0,m)
					{
						if(DP[i][a][l][j]!=-1)
						val[i][j]=max(DP[i][a][l][j],val[i][j]);
					}
				}
			}
		}
		I(OP,-1);
		OP[0][0]=0;
		L(i,1,n)
		{
			L(j,0,k-1)		//req reaminder
			{
				L(l,0,k-1)  //cur remainder
				{
					lli req=(k-l+j)%k;
					if(OP[i-1][req]!=-1&&val[i][l]!=-1)
						OP[i][j]=max(OP[i][j],OP[i-1][req]+val[i][l]);
					OP[i][j]=max(OP[i][j],OP[i-1][j]);
				}
			}
		}
		cout<<OP[n][0]<<endl;
	}
	return 0;
}
