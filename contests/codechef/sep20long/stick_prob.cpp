#include<bits/stdc++.h>
using namespace std;

// int countDistinct(int arr[], int n) {
//     sort(arr, arr + n);
//     int res = 0;
//     for (int i = 0; i < n; i++) {
//         while (i < n - 1 && arr[i] == arr[i + 1])
//             i++;
//         res++;
//     }
//     return res;
// }
int countDistinct(long int arr[], long int n) {
    unordered_set<int> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if(arr[i] !=0){
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            res++;
      }}
    }
    return res;
}

int main(){
      int t;
      cin>>t;

      while(t!= 0) {
            long int n;
            cin>>n;
            long int arr[n];
            for (int i=0; i<n; i++)
                  cin>>arr[i];
            cout<<countDistinct(arr, n)<<endl;
            t = t-1;
      }
}
