#include<bits/stdc++.h>
using namespace std;

int main(){
      int n, skip;
      int count = 0;
      int sum =0;
      cin>>n;
      int city_cost[n];
      for (int i=0; i<n; i++){
            cin>>city_cost[i];
            if(city_cost[i] == -1)
                  count = count+1;
      }
      int n1 = sizeof(city_cost)/sizeof(city_cost[0]);
      //for (int i=0; i<n; i++)
      //      cout<<city_cost[i]<<'\n';
      //for (int i=0; i<n; i++){
      //      if(city_cost[i] == -1)
            //      count = count+1;}
      cin>>skip;
      //cout<<count;
      //for (int i=0; i<n; i++){
      if(count>skip || city_cost[n-1] == -1)
            cout << "-1";
      else{
            int x = skip-count;
            sort(city_cost, city_cost+n1, greater<int>());
            for (int i=x; i<n; i++){
                  //cout<<city_cost[i]<<'\n';}}
                  if(city_cost[i] != -1)
                  sum = sum+city_cost[i];
                  else{
                        // cout<<sum;
                        break;
                  }

            }
            cout <<sum;
      }
            // cout <<sum;
      //}

}
