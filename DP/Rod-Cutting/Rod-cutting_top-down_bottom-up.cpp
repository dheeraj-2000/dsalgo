
#include<iostream>
#include<climits>
#include<ctime>
using namespace std;
int max(int a, int b){ return a>b?a:b;}
int bottom_up(int p[],int n)
{
  int r[n+1];
  r[0]=0;
  for(int i=1;i<=n;i++)
  {
    int value=INT_MIN;
      for(int j=1;j<=i;j++)
        value = max(value,p[j]+r[i-j]);
      r[i]=value;
  }
  return r[n];
}
int m_top_down(int p[],int n,int r[])
{
  int value;
  if(r[n]>=0)
    return r[n];
  if(n==0)
    value=0;
  else
  {
    value=INT_MIN;
    for(int i=1;i<=n;i++)
      value=max(value,p[i]+m_top_down(p,n-i,r));
  }
  r[n]=value;
  return value;
}
int top_down(int p[],int n)
{
  int r[n+1];
  for(int i=0;i<=n;i++)
    r[i]=INT_MIN;
  return m_top_down(p,n,r);
}

int main()
{
  clock_t t;
  int a[1000],n;
  cout<<"\t\t\tEnter length of the rod : ";
  cin>>n;
  cout<<"Enter price for different size rod length : "<<endl;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  t=clock();
  cout<<"Top Down approach : ";
  cout<<"\tMaximum profit : "<<top_down(a,n)<<endl;
  t=clock()-t;
  cout<<"Time :"<<((double)t)/CLOCKS_PER_SEC<<endl;
  t=clock();
  cout<<"Bottom up approach : ";
  cout<<"\tMaximum profit : "<<bottom_up(a,n)<<endl;
  t=clock()-t;
  cout<<"Time :"<<((double)t)/CLOCKS_PER_SEC<<endl;

}
