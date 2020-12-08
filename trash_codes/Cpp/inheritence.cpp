#include<iostream>
using namespace std;

class Entitity{
public:
      float X, Y, z;
      void move(float xa, float ya){
            X = xa+5;
            Y += ya;
      }
};

class Player : public Entitity{
public:
      const char* name;
      // float X, Y;
      //
      // void move(float xa, float ya){
      //       X += xa;
      //       Y += ya;
      // }

      void print_name(){
            cout<< name<<endl;
      }
};

int main(){
      cout<<sizeof(Player)<<endl;
      Player player;
      player.move(5, 5);
      player.move(player.X, 5);
      cout<<player.X<<endl;
      cout<<sizeof(Entitity)<<endl;
      cout<<sizeof(Player)<<endl;
}
