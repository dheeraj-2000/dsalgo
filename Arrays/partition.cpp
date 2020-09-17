#include<iostream>
#include<vector>

using namespace std;

int solve(int A, vector<int> &B) {
      int sum=0;
      int one_third_sum, temp_sum1=0,temp_sum2=0, result = 0;
      for(auto i: B)
            sum +=B[i];

      if(sum%3 == 0)
            one_third_sum = sum/3;
      else
            return 0;
      vector<int> temp(A, 0);
      for(int i=A-1; i>=0; i++){
            temp_sum1 += B[i];
            if(temp_sum1 == one_third_sum )
                  temp[i]=1;
      }

      for(auto i : B){
            temp_sum2 += B[i];
            if(temp_sum2 == one_third_sum ){
                  for(int j = i+2; j<A; j++) {
                        if(temp[j]==1)
                              result++;
                  }
            }
      }

      return result;
}



int main(){
      int n, input;
      cin>>n;
      vector<int> v(n);
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      cout<<solve(n, v);

}
