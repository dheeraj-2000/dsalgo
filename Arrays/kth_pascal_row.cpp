#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> solve(int A) {
      vector <int> ans;
      int i = A + 1, c = 1;
      for(int j=1; j<=i; j++){
          ans.push_back(c);
          c = c*(i - j)/j;
      }
      // return ans;

      // for (int i=0; i<ans.size(); i++)
      //       cout<<ans[i];
}
//
// vector<int> solve(int A) {
//       vector <int> result;
//
//       long long int num = pow(11, A-1);
//       while(num>=0){
//             long long int x = num%10;
//             result.push_back(x);
//             num = num/10;
//       }
//       for (auto i: result)
//             cout<<i;
//       // return result;
// }
//


int main(){
      int n, input;
      cin>>n;
      // vector<int> v(n);
      // for(auto i=0; i<n; i++){
      //       cin>>input;
      //       v.push_back(input);
      // }
      solve(n);
      // for(int i=0; i<v.size(); i++)
      //       cout<<v[i];

}
