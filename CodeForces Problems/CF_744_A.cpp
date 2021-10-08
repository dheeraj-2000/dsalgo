Problem link : https://codeforces.com/contest/1579/problem/A

#include<bits/stdc++.h>
using namespace std;


int main()
{
     int t;
     cin>>t;
     while(t--) {

          //Input
          string s;
          cin >> s;

          int n = s.size();

          //No matter which action is chosen, after this action is performed exactly one letter 'B' is erased from the string and exactly two letters in total are erased from the string

          int cntB = 0;
          int cntAC = 0;

          for (int i = 0; i < n; i++) {
               if (s[i] == 'B') cntB++;
               else cntAC++;
          }

          if (cntAC == cntB) cout << "YES" << endl;
          else cout << "NO" << endl;
     }
     return 0;
}
