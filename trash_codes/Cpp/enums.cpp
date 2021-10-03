#include<iostream>
using namespace std;

// enum val{
//       A, B, C
// };

// int a =0;
// int b=1;
// int c=2;

// int main(){
//       val value = B;
//
//       cout<<A<<B<<C;
//       if(value ==1){
//             cout<<"match";
//       }
// }

enum State {WORKING = 0, FAILED, FREEZED};
// enum State currState = 2;

enum State FindState() {
    return FAILED;
}

int main() {
   (FindState() == WORKING)? printf("WORKING"): printf("NOT WORKING");
   return 0;
}
