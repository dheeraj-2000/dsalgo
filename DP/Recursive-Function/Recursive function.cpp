/******************************************************************************

Design and implement a non-recursive dynamic programming based algorithm to
evaluate f(n) = 2(f(n − 1) ∗ f(n − 2))) + 1, where n ≥ 2, f(0) = 1 and f(1) = 2.

******************************************************************************/
#include<iostream>
using namespace std;

long int sum(long int n)
{
    long int a[n+2];
    a[0]=1;
    a[1]=2;
    a[2]=5;
    for (long int i=3;i<=n;i++)
      a[i]=2*a[i-1]*a[i-2] + a[i-1];
    return (a[n]);
}
int main()
{
  long int n;
  char c='y';
  while(c == 'y' || c == 'Y')
  {
    cout<<"\nEnter a number: "<<endl;
    cin>>n;
    cout<<"Answer : "<<sum(n)<<endl;
    cout<<"To continue press y  else n:"<<endl;
    cin>>c;
  }
}
