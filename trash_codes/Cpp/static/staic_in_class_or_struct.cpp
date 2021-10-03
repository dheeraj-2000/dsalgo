#include<iostream>
using namespace std;

class s{
public:
      static int x, y;

      static void print(){
            cout<<x<<", "<<y<<endl;
      }
};

int s::x;
int s::y;
int main(){
      // s e1;
      s::x = 2;
      s::y = 3;

      // s e2 ;
      s::x = 5;
      s::y =10;

      s::print();
      s::print();

}
