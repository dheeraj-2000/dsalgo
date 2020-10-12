/*
This problem can be solved with recursive approach.

OBSERVATION:
Given n, we'll be having (n-1)! permutations starting with 1, (n-1)! permutations starting with 2, and so on.. So, each block is of size (n-1!).
So, this can be used to find out the first digit of the required sequence. Say, n=4 and k=15, then, k/(n-1!) = 2.5 so, the required permutation will be lying somewhere in the 3rd block. So, the number starts with 3.
APPROACH:
Kth Permutation sequence can be formed by choosing the 1st digit and then the rest of the digits one by one.
We can find the first digit in the sequence, and then apply the same technique to keep finding the first digit of the remaining part of the sequence until the whole sequence is found.
EXAMPLE:
We can find the first digit in the number and keep updating n and k to find the first digit in the remaining part of the number.
Say, n=4 and k=15. Now, nums = {1,2,3,4}. ind = ceil(k/(n-1!) = 3. So, num is 3{}{}{}.
k = k%(n-1!), n=n-1
Now, n=3, k=3. nums={1,2,4}. ind = ceil(3/2) = 2. So, num is 32{}{}.
n=2,k=1, nums={1,4}. ind = ceil(1/2) = 1. So, num is 321{}.
n=1, k=1, nums = {4}. ind=ceil(1/1)=1. So, nums is 3214.
NOTE:
Think about the case when k becomes zero before n. When does this happen? k becomes zero when n-1!=k (coz, k = k%n-1!). This means that this is the last element in the corresponding block, and obviously in this case, the remaining part of the permutation is going to be all the remaining digits arranged in descending order.
eg: n=3,k=2.
*/

#include <bits/stdc++.h>
using namespace std;

  int fact[15];
  string s="";
  int c=0;
  void calc(int n,int k,int m,vector &v){ //m always decreases by 1
  if(m<0){
  return ;
}

  int d=fact[m];// factorial of m 

  int x=ceil(k*1.0/d*1.0);// index of the element that has to be taken from vector
  c=c*10 + v[x-1];        // forming the number 
  s=to_string(c);         // converting  number to string 
  v.erase(v.begin()+x-1);  // now remove that digit as permutation has every digit once
  int next_k=k-((x-1)*d);     // finding the next k which is to be further processed with the same logic
  calc(n,next_k,m-1,v);   //its a recursive function
}

class Solution {
public:
string getPermutation(int n, int k) {
vector v;

    fact[0]=1,fact[1]=1,fact[2]=2;// pre compute factorial
    for(int i=3;i<=n;i++){
        fact[i]=fact[i-1]*i;
    }
    c=0;
    s="";
    for(int i=1;i<=n;i++){ // insert the first permutation in sorted order
        v.push_back(i);
    }
    calc(n,k,n-1,v);
    
    return s;
    
}
};
