#include<bits/stdc++.h>
using namespace std;
#define P(x) cout<<x<<endl;
#define take_input cin>>x;


int inc(int& val){
      val ++;
      // return val;
}

int res(int* val){
      // val ++;
      (*val)++;
      // return val;
}


int main(int argc, char const *argv[]) {
      int a = 10;
      // int* ptr = &a;
      inc(a);
      P(a)

      res(&a);
      P(a)


      int* ptr = &a;
      int& ref = a;
      P(a)
      P(ptr)
      P(&ref)


      ref = 13;
      P(ref)
      P(a)
}
