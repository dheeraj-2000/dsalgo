#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(int argc, char const *argv[]) {

      auto mycomparator = [](int left, int right){return (left) < (right) ; };      // this comparator is used to give priority to the element with your rule
      priority_queue<int, vector<int>, decltype(mycomparator)> dheeraj_pq(mycomparator);

      for(int ele: {1,2,4,21,6,8}){
            dheeraj_pq.push(ele);
      }

      while(!dheeraj_pq.empty()){
            cout<<dheeraj_pq.top()<<'\t';
            dheeraj_pq.pop();
      }

      // return 0;
}
