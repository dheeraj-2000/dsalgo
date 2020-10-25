#include<iostream>
#include<vector>
#include<algorithm>
// #include<maxlen>

using namespace std;



bool solve(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int i=1,j=0,c=1;
    while(i<arrive.size()){
        if(arrive[i]>=depart[j]){
            i++;
            j++;
        }
        else{
            i++;
            c++;
        }
    }
    if(c>K)return false;

    return true;
}

// bool solve(vector<int> & arrive, vector<int> & depart, int k ){
//
//       vector< pair <int, int> > result;
//
//       for(int i=0; i<arrive.size(); i++){
//             result.push_back(make_pair(arrive[i], 1));
//             result.push_back(make_pair(depart[i], 0));
//       }
//       sort(result.begin(), result.end());
//
//       int cur_booked=0, max_booked=0;
//
//       for(int i=0; i<result.size(); i++){
//             if(result[i].second == 1){
//                   cur_booked ++;
//                   max_booked = max(max_booked, cur_booked);
//                   if(max_booked > k)
//                         return false;
//             }
//             else cur_booked++;
//       }
//
//       return true;
//
// }


int main(){
      int n, input, input2, k;
      cin>>n;
      vector<int> arrive(n);
      vector<int> depart(n);
      for(int i=0; i<n; i++){
            cin>>input;
            arrive.push_back(input);
      }

      for(int i=0; i<n; i++){
            cin>>input2;
            arrive.push_back(input2);
      }

      cout<<solve(arrive, depart, k);
}
