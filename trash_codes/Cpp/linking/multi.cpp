#include<iostream>
using namespace std;


void log(const char* message);

static int mul(int a, int b){
      log("dheeraj");
      return a * b;
}

int main(){
      cout<<mul(2, 3);

}
