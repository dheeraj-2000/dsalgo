#include<bits/stdc++.h>
#include<vector>


using namespace std;

int solve(vector<int> &B) {
      int sum=0;
      int x = B.size();
      int one_third_sum, temp_sum1=0,temp_sum2=0, result = 0;
      for(int i=0; i<B.size(); i++)
            sum = sum +B[i];


      cout<<sum<<endl;
      if(sum%3 == 0)
            one_third_sum = sum/3;
      else
            return 0;
      cout<<one_third_sum<<endl;
      vector<int> temp(B.size(), 0);

      for(int i=x-1; i>=0; i--){
            temp_sum1 += B[i];
            if(temp_sum1 == one_third_sum )
                  temp[i]=1;
      }
      cout<<temp_sum1<<endl;
      for(int i=0; i<B.size(); i++){
            temp_sum2 += B[i];
            if(temp_sum2 == one_third_sum ){
                  for(int j = i+2; j<B.size(); j++) {
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
      cout<<solve(v);

}
