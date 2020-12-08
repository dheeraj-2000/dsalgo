// Video Link:  https://youtu.be/FXhALMsHwEY

#include<iostream>
using namespace std;

class entity{
public:
      float X, Y;

      // void init(){            //to initialize the values of variable t zero
      //       x = 0;
      //       y = 0;
      // }

      // entity(){                     // Constructor is a method that is called every time you instanciate a class
      //       x = 0.0f;                // In Java we don't need to initialize variable to zero like this they automaticallu initaialized to zero
      //       y = 0.0f;
      // }

      entity(float x, float y){
            X = x;
            Y = y;
      }

      void print(){
            cout<<X<<' '<<Y<<endl;
      }

};


int main(){
      int m;
      entity e(10, 5);
      // e.init();   // every time we instanciate the class, we have to define this init function to initialize values of variable to zero
      e.print();
      // cout<<e.x<<endl;
      cout<<m;

      // entity e1;
      // e1.init();
}
