#include<bits/stdc++.h>
using namespace std;
int maxArr(vector<int> &A){
      int n=A.size(),max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX,ans=INT_MIN;
      for(int i=0;i<n;i++){
            max1=max(max1, A[i]+i);
            min1=min(min1, A[i]+i);
            max2=max(max2, -A[i]+i);
            min2=min(min2, -A[i]+i);
      }
      ans = max((max1-min1), (max2 - min2));
return ans;
}

int main(){
      int n, input;
      cin>>n;
      vector<int> v;
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      cout<<maxArr(v);
}
