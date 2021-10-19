#include<iostream>
using namespace std;

string lcs (string a, string b){
	int n=a.length(), m=b.length(), dp[n+1][m+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}

	int ind=dp[n][m];
	char result[ind+1];
	int i=n,j=m;
	result[ind]='\0';
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
			{
				result[ind-1]=a[i-1];
				i--;j--;ind--;
			}
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else
		{
		 j--;
		}
	}

	return result;
}

int main(){
	string s1,s2;
	cout<<"Enter 1st string\n";
	cin >>s1;
	cout<<"Enter 2nd string\n";
	cin >>s2;
	cout << "The Largest Common Subsequence found is: "<<lcs(s1,s2);
}
