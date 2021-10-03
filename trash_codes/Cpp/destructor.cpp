// Video Link:  https://youtu.be/FXhALMsHwEY

#include<iostream>
using namespace std;

class entity{
public:
      float X, Y;

      entity(){
            X = 0.0f;
            Y=0.0f;
            cout<< "Created entity "<<endl;
      }

      // entity(float x, float y){
      //       X = x;
      //       Y = y;
      // }

      ~entity(){
            cout<< "Destroyed entity "<<endl;
      }

      void print(){
            cout<<X<<' '<<Y<<endl;
      }

};

void function(){
      entity e;
      // e.init();   // every time we instanciate the class, we have to define this init function to initialize values of variable to zero
      e.print();
      cout<<e.X<<endl;
}

int main(){

      function();
      int m;
      cout<<m<<endl;
      entity e1;
      cout<<e1.X<<endl;
      e1.~entity();

}
