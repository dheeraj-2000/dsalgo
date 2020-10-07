#include<iostream>
#include<vector>

using namespace std;
int main(){
      int t;
      cin >>t;
      while(t--){
            long int n,k, res=0, reached = 0;
            cin>>n>>k;
            // vector<int> v(n);
            int arr[n];
            for(int i=0; i<n; i++){
                //   long int input;
                //   cin>>input;
                cin>>arr[i];
                //   v.push_back(input);
            }
            // while(days++){
            //       sum += arr[i];
            // }
            for(int i=0; i<n; i++){
                  // sum +=arr[i];
                  // res = i
                  arr[i+1] = arr[i+1] + (arr[i]-k);

                  if(arr[i] < k){
                        res = i;
                        reached = 1;
                        break;
                  }
                  // cout<<i<<endl;
            }
            // if (reached == 1) cout<<res+1<<endl;
            // else cout<< n + arr[n-1]/k;
            // cout<<arr[n-1];
            (reached == 1) ? cout<<res+1<<'\n' : cout<<n + arr[n-1]/k<<endl;



      }
}
