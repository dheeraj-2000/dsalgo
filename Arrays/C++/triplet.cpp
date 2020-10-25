#include<bits/stdc++.h>
#include<vector>


using namespace std;

// // Using Binary search (nlogn)
// bool solve(vector<string> &A) {
//       sort(A.begin(), A.end());
//       int i=0;
//       int j= A.size()-1;
//
//       while(j-i>=2){
//             int mid_num= i+j/2;
//             double a = stof(A[i]);
//             double c = stof(A[j]);
//             double b = stof(A[mid_num]);
//             double triplet_sum = a + b + c;
//             if(triplet_sum >2) j--;
//             if(triplet_sum < 1) i++;
//             else return true;
//       }
//
//       return false;
// }

// // Using random function to pick the elements
bool solve(vector<string> &A) {
      vector<double> B;
      int i1,j,k;

      for(auto i:A){
          B.push_back(stod(i));
      }

      for(int ii=0;ii<1000;++ii){
            i1 = (rand()%A.size());
            j = (rand()%A.size());
            k = (rand()%A.size());

            if (i1 != j && j != k && i1 != k){
                  if(B[i1]+B[j]+B[k]>1 && B[i1]+B[j]+B[k]<2)
                        return 1;
            }
      }
      return 0;
}


int main(){
      int n;
      string input;
      cin>>n;
      vector<string> v;
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      cout<<solve(v);

}
