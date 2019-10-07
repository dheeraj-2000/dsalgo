
#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s1="XMJYAUZ";
  string s2="MZJAWXU";
  //cin>>s1;
//  cin>>s2;
  int i,j;
  int m=s1.length();
  int n=s2.length();
  int lookup[m+1][n+1];
  for(i=0;i<=m;i++)
  {
    lookup[i][0]=0;
  }
  for(i=0;i<=n;i++)
  {
    lookup[0][i]=0;
  }

  for(i=1;i<=m;i++)
  {
      for(j=1;j<=n;j++)
          {
            if(s1[i-1]==s2[j-1])
                    lookup[i][j]=lookup[i-1][j-1]+1;
            else
                    lookup[i][j]=max(lookup[i-1][j],lookup[i][j-1]);
          }
  }
  cout<<"largest common subsequence "<<lookup[m][n];

}
