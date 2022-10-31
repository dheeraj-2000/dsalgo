#include <iostream>
using namespace std;
int main()
{
    int r,n,seen[10]={0};
    cout<<"Enter a number: ";
    cin>>n;
    while(n!=0)
    {
        r=n%10;
        if(seen[r]==1)
        break;
        seen[r]=1;
        n/=10;
    }
    if(n>0)
    cout<<"Yes there are repeated digits in the entered number.";
    else
    cout<<"No there are no repeated digits in this number.";
    return 0;
}
