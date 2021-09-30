#include<iostream>
using namespace std;
#define P(x) cout<<x<<endl;
// #define take_input cin>>x;

class Player{
public:
      int x, y;
      int speed;

// Functions inside the classes are called methods
      void move(int xa, int ya){
            x = xa+ speed;
            y = ya + speed;
      }


};


void move(Player& player, int xa, int ya){  // we can also use it as class methods
      player.x = xa+ player.speed;
      player.y = ya + player.speed;
}

int main(){
      Player player;
      player.x = 5;
      P(player.x);

      move(player, 1, -1);

      player.move(1, -1);   // Use this if using class methods
}
