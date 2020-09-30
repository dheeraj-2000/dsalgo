#include<bits/stdc++.h>
#include <queue>
using namespace std;
int main (){
      int n, check = 0, pair=0;
      cin>>n;
      queue<string> bride;
      queue<string> groom;
      string b[n], g[n];
      for (int i=0; i<n; i++)
            bride.push(b[i]);

      for (int i=0; i<n; i++)
            groom.push(g[i]);

      while(!bride.empty()){
            if(groom.empty())
                  break;

            string b1 = bride.front();
            string g1 = groom.front();

            if(b1==g1){
                  bride.pop();
                  groom.pop();
                  pair++;
                  check=0;
            }
            else if (check==n){
                  break;
            }
            else
                  groom.pop();
                  groom.push(g1);
                  check++;
      }

      int ans=n-pair;
      cout<<ans;
      return 0;

}
