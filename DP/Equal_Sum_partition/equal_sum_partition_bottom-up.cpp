// tabulation /bottom up approach
#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
int Equal_partition_sum(int inputarray[],int size,int sum)
{
    for(int rowindex = 0 ; rowindex<size+1;rowindex++)
    {
            DP[rowindex][0] = 1;
    }
    for(int colindex = 1; colindex<=sum;colindex++)
            DP[0][colindex] = 0;

    for(int rowindex = 1; rowindex < size+1; rowindex++)
    {
        for(int colindex = 1; colindex <= sum; colindex++)
        {
            if(inputarray[rowindex-1]<=colindex)
            {
                DP[rowindex][colindex] = DP[rowindex-1][colindex-inputarray[rowindex-1]] || DP[rowindex-1][colindex];
            }
            else
            {
                DP[rowindex][colindex]  = DP[rowindex-1][colindex];
            }
            
        }
    }
    return DP[size][sum];
}
int main()
{
    int size;
    cin>>size;
    int inputarray[size];
    for(int currentIndex = 0  currentIndex<size; currentIndex++)
                cin>>inputarray[currentIndex];
    
    int sum = 0;
    for(int currentIndex = 0; currentIndex < size ; currrentIndex++)
        sum += inputarray[currentIndex];

        int ans;
    if(sum % 2 != 0)
        ans = false;
    else
    {
        ans = Equal_partition_sum(inputarray,size,sum/2);
    }
    if(ans == 0)
    cout<<false;
    else
    {
        cout<<true;
    }
}
