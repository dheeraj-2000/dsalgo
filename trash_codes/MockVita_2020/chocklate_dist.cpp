#include<bits/stdc++.h>
using namespace std;

int i, j;
int calStudent(int i, int j){
      int count =0;
      if(i>j){
            // int temp = i-j;
            while(i==0 || j == 0){

                  int temp = i-j;
                  if(temp>j)
                        i = temp;
                  else{
                        i=j;
                        j=temp;
                  }
                  count = count+1;
            }
      }

      else {
            while(i==0 || j == 0){
                  // int count =0
                  int temp = j-1;
                  if(temp>i)
                        j = temp;
                  else{
                        j=i;
                        i=temp;
                  }
                  count = count+1;
            }

      }
      return count;

}

int main(){
      int minl, maxl, minw, maxw;
      cin>>minl;
      cin>>maxl;
      cin>>minw;
      cin>>maxw;

      for (int i=minl; i<=maxl; i++){
            for(int j=minw; j<=maxw; j++){
                  calStudent(i, j);
            }
      }
      // calStudent(5, 3);

      cout<<calStudent;

}
