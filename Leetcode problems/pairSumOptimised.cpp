// select two numbers such that thier sum is equal to n given that atleast one such pair exists nlogn approach 
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> towSum(vector<int> s,int num)
{
    unordered_set <int> sum;
    int i=0,j=s.size();
    vector<int> ind;  
    for(i=0;i<j;i++)
    {
        if(sum.find(num-s[i])!=sum.end())
        {
        ind={s[i],num-s[i]};
        return ind;
        }
        sum.insert(s[i]);
    }
} 

    
int main()
{
    vector<int> sum={10,5,2,3,-6,9,11};
    vector<int> ind=towSum(sum,11);
    cout << ind[0] << ind[1];
    return 0;
}