//memoization solution
#include<bits/stdc++.h>
using namespace std;
int DP[100][100]; //take the size according to the constraints provided
for(int rowindex = 0 ; rowindex<100;rowindex++)
{
    for(int colindex = 0; colindex<100;colindex++)
    {
        DP[rowindex][colindex] = -1;
    }
}
int Equal_partition_sum(int inputarray[],int size,int sum)
{
    //base case
    if(sum == 0)
    {
        return 1;  //if sum is 0 then we can form a empty subset
    }
    else if(size == 0) //if size of array is zero means no elements then we cannot form a subset
    return 0;
if(DP[size][sum])
   {
       return DP[size][sum];
   }
        if(inputarray[size-1]<=sum) //if currentElement of array is less than or equal to desired sum then only we can include it in the subset
        {
            DP[size][sum] = (Equal_partition_sum(inputarray,size-1,sum-inputarray[size-1]) || Equal_partition_sum(inputarray,size-1,sum) );
        }
        else
        {
          DP[size][sum] = Equal_partition_sum(inputarray,size-1,sum);
        }
        return DP[size][sum]
        

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
        ans = 0;
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