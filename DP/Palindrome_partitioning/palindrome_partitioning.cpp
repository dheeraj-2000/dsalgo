/**     Author: Ajaysinh Rajput       **/

//      Palindrome Partitioning        // 

/*  
Problem: Given a string A, partition A such that every substring of the partition is a 
         palindrome. Return the minimum cuts needed for a palindrome partitioning of A.

==> Solved Using Top-Down DP Approach
*/


#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;


// To check whether given string is palindrome or not
bool ispalindrome(string s,int left,int right)
{
    while(left<right)
    {
        if(s[left]!=s[right])
            return false;
        left++,right--;
    }
    return true;
}


int palindrome_part(string s,int left,int right,vector<vector<int> > &Min_cut)
{

    // if left pointer exceeds right pointer then exit
    if(left>=right)
        return 0;

    // if we have already calculated it then simply return it
    if(Min_cut[left][right]!=-1)
        return Min_cut[left][right];

    // if current string is palindrome then there is no need to partition
    if(ispalindrome(s,left,right))
        return 0;

    // Min represents minimum cuts required to make palindrom partition in range [left,right]
    int Min=INT_MAX;
    // itrative cut in range [left,right-1] to find minimum needed cuts
    for(int cutting_index=left;cutting_index<right;cutting_index++) 
    {
        // Min_left stores minimum cuts needed for interval [left,cutting_index]
        // Min_right stores minimum cuts needed for interval [cutting_index+1,right]
        int Min_left,Min_right;

        //calculate for left side
        if(Min_cut[left][cutting_index]!=-1)
            Min_left = Min_cut[left][cutting_index];
        else
        {
            Min_left = palindrome_part(s,left,cutting_index,Min_cut);
            Min_cut[left][cutting_index] = Min_left;
        }

        // calculate for right side
        if(Min_cut[cutting_index+1][right]!=-1)
            Min_right = Min_cut[cutting_index+1][right];
        else
        {
            Min_right = palindrome_part(s,cutting_index+1,right,Min_cut);
            Min_cut[cutting_index+1][right] = Min_right;
        }

        // Min_Cut = Min_Cut for left part + Min_cut for right part + 1(due to current cut)
        int Current_Min = Min_left + Min_right + 1;
        // update Min 
        if(Current_Min < Min)
            Min = Current_Min;
    }
    // Store minimum cuts required for range [left,right] and then return it
    return Min_cut[left][right]=Min;

}



int main() 
{

    string A;
    cin>>A;
    // Min_cut is used to store minimum cuts for substring of s
    vector<vector<int> > Min_cut(A.length(),vector<int>(A.length(),-1));
    cout<<"\n Minimum cuts needed for a palindrome partitioning of given string is: "<<palindrome_part(A,0,A.length()-1,Min_cut)<<'\n';

    return 0;

}
