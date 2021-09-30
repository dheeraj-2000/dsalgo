#include<iostream>
using namespace std;
// static int i=0;

void func(){
      static int i=0;
      i++;
      cout<<i<<endl;
}

int main(){
      func();
      func();
      // i=10;
      func();
      func();
      func();
      func();
}
