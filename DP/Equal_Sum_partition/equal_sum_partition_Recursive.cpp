/* Problem statement :-
Given an array determine whether a given array can be partitioned in 2 subsets such that the sum of elements in them is equal.
logic:- If the total sum of array elements is odd then it can never be split into two halves such that sum is equal
but if sum is even then it can be split into two subsets consisting of equal sum*/
#include<bits/stdc++.h>
using namespace std;

bool Equal_partition_sum(int inputarray[],int size,int sum)
{
    //base case
    if(sum == 0)
    {
        return true;  //if sum is 0 then we can form a empty subset
    }
    else if(size == 0) //if size of array is zero means no elements then we cannot form a subset
    return false;

        if(inputarray[size-1]<=sum) //if currentElement of array is less than or equal to desired sum then only we can include it in the subset
        {
            return (Equal_partition_sum(inputarray,size-1,sum-inputarray[size-1]) || Equal_partition_sum(inputarray,size-1,sum) );
        }
        else
        {
            return Equal_partition_sum(inputarray,size-1,sum);
        }
        

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

        bool ans;
    if(sum % 2 != 0)
        ans = false;
    else
    {
        ans = Equal_partition_sum(inputarray,size,sum/2);
    }
    cout<<ans;
    
}