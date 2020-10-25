#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
      int n, input;
      cin>>n;

      // By default Decreasing order

      // Also it is be MaxHeap by default
      priority_queue<int> my_pq_default;
      for(int i=0; i<n; i++){
            cin>>input;
            my_pq_default.push(input);
      }

      while(!my_pq_default.empty()){
            cout<<my_pq_default.top()<<'\t';
            my_pq_default.pop();
      }

      cout<<endl;

      // get element in Increasing order by using constructor

      // This can be said as MinHeap as elements are in ascending order
      priority_queue<int, vector<int>, greater<int>> my_pq_increasing;
      for(int i=0; i<n; i++){
            cin>>input;
            my_pq_increasing.push(input);
      }

      while(!my_pq_increasing.empty()){
            cout<<my_pq_increasing.top()<<'\t';
            my_pq_increasing.pop();
      }
}
