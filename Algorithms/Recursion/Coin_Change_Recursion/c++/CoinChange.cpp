#include<iostream>
using namespace std;
int coinchange(int amt, int c[],int n,int currentcoin)
{
  if(amt==0)
    return 1;

  if(amt<0)
    return 0;
  int ways=0;
  for(int i=currentcoin;i<n;i++)
  {
        ways+=coinchange(amt-c[i],c,n,i);//keep a track of current coin otherwise we would repeat combinatin such as 1+1+2=4 is same as 1+2+1=4
  }
  return ways;
}
int main()
{
  //enter the no. of coin denomination you have
  int n;
  cin>>n;
  int c[n];
  //enter the coin denimation in array of size n
  for(int i=0;i<n;i++)
  {
    cin>>c[i];
  }
  //enter the amount for which you need no. of ways to get that amount
  int amt;
  cin>>amt;
  cout<<"no. of ways to get amount from given denominations is :"<<coinchange(amt,c,n,0)<<endl;

  }
