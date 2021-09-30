#include<iostream>
using namespace std;

class Entitity{
public:
      string Get_name(){ return "Entity" ;}

};

class Player : public Entitity{
private:
      string m_name;
public:
      Player(const string& name) : m_name(name) { }

      string Get_name(){ return m_name; }


};

int main(){
      /* new operator
      // int a = 2;
      // int* b = new int[50];   //200 bytes
      // delete[] b;   // delete array memory
      // int* b = new int;

      Entity* e = new Entity()     //allocates the mwmory and call the Constructor
      delete e;   // it also calls destructor along with deleting the memory
      Entity* e = (Entity*)malloc(sizeof(Entity));   // This way it only allocates the memory but doesn't calls the Constructor

      */

      Entitity entity;
      cout<<entity.Get_name()<<endl;

      // Player player;
      // cout<<player.Get_name("dheeraj")<<endl;
      Player* p = new Player("dheeraj");
      cout<< p->Get_name()<<endl;
}
