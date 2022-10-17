#include<iostream>
#include<numeric>

using namespace std;

int main()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3},msum=INT_MIN,sum=0;    

    int l=sizeof(arr)/sizeof(int);
    
    for(int i=0;i<l;i++)
    {
        sum+=arr[i];
        if(msum<sum)
            msum=sum;
        if(sum<0)
            sum=0;
    }

    cout<<msum;

    return 0;
}