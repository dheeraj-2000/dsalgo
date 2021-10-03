#include<iostream>
using namespace std;
int fact(int);
int main()
{
 int n,f;

 cin>>n;
 f=fact(n);
 cout<<f;
 return 0;
}
int fact(int n)
{
 if (n==0)
 {
  return 1;
 }
 else
 {
  return (n*(fact(n-1)));
 }
}
