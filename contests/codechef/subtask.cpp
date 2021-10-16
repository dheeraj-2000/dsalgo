#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  for (int i = 0; i < t; i++)
  {
    /* code */
    
    int n,m,k,count=0,total=0;
  
    cin>>n>>m>>k;
    int arr[n];
    for (int j = 0; j < n; j++)
    {
      /* code */
      cin>>arr[j];
    }
     for (int k = 0; k < n; k++)
    {
      /* code */
      count+=arr[k];
      
    } 
    if(n==count){
      cout<<"100"<<endl;
    }
    else{
      int flag=0;
      for(int i=0;i<m;i++){
        if(arr[i]==1){
          flag=1;
        }
        else{
          flag=0;
          break;
        }

      }
      if(flag==0){
        cout<<"0"<<endl;
      }
      else{
        cout<<k<<endl;
      }
    }
  }
  return 0;
}
