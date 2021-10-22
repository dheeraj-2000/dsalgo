#include <iostream>

using namespace std;

/*
Grid Based Dynamic Programming 

Common Variants : 
(a) finding minimum/maximum Cost path in a grid 
(b) finding the number of ways to reach a particular position from a given starting point in 2-D grid and so on

Given the cost matrix, you have to find out the cost required to move to a certain cell (x,y) 
you can move only in either left or right direction 
suppose i am standing at a particular cell (x,y) then the cost of reaching this cell is going to be : 
dp[x][y] = min(dp[x-1][y],dp[x][y-1]) + cost[x][y] for all x,y in n

The time complexity of this approach is : O(N^2)

Note : first row and column are going to be different because the are reachable only by moving right for rows and
moving only down for columns

at each cell you can also store the direction. That will help you to retrace the path you came from 
*/

int minCost(int R,int C,int cost[][100])
{
	int dp[R][C]={0};

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			//base case 

			if(i==0 and j==0)
			{
				dp[i][j]=cost[0][0];
			}

			else if(i==0)
			{
				dp[i][j]=dp[0][j-1]+cost[i][j];
			}

			else if(j==0)
			{
				dp[i][j]=dp[i][0]+cost[i][j];
			}

			else 
			{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
			}
		}
	}

	cout<<"The dp array is :"<<endl;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cout<<dp[i][j]<<" \t";
		}

		cout<<endl;
	}

	//tracing our path 
	
	cout<<"The path followed is : "<<endl;
	cout<<cost[0][0]<<" --> ";
	int i=0,j=0;
	while(i<R-1 && j<C-1)
	{
		if(dp[i+1][j]<dp[i][j+1])
		{
			cout<<cost[i+1][j]<<" --> ";
			i++;
		}
		else
		{
			cout<<cost[i][j+1]<<" --> ";
			j++;
		}
	}
	cout<<cost[R-1][C-1];
	cout<<endl;

	return dp[R-1][C-1];
}

int main()
{
	int n,m;
	cin>>n>>m;
	int dp[n][m]={0};

	int cost[n][100];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>cost[i][j];
		}
	}

	int x,y;
	cin>>x>>y;
	
	cout<<minCost(x,y,cost)<<endl;

	return 0;
}