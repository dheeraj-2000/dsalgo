#include<bits/stdc++.h>
using namespace std;

bool pow_of_two(int num){
      if (num <=1)
            return 0;
      else return ( ceil(log2(num)) == floor(log2(num)) );
}

int main(){
      int t;
      cin>>t;
      while(t--){
            int num;
            cin>>num;
            if(pow_of_two(num)){
                  cout<<"-1"<<endl;
                  continue;
            }

            int arr[num];
            arr[0]=2;
            arr[1]=3;
            arr[2]=1;

            if (num == 1){
                  cout<<"1"<<endl;
                  continue;
            }

            if (num == 3){
                  arr[0]=1;
                  arr[1]=3;
                  arr[2]=2;
                  for(int i=0; i<3; i++)
                        cout<<arr[i]<<" ";
                  cout<<endl;
            }
            else{
                  for(int i=3; i<num; i++)
                        arr[i] = i+1;

                  for(int i=3; i<num; i = i+2){
                        if(pow_of_two(arr[i])){
                              swap(arr[i], arr[i+1]);
                        }
                  }

                  for(int i=0; i<num; i++)
                        cout<<arr[i]<<" ";
                  cout<<endl;
            }
      }

}
