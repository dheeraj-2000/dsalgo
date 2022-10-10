#include <iostream>
using namespace std;
//recursive fibonacci function to find our nth digit of fibonacci series
int fibonacci(int x) {
   if((x==1)||(x==0)) {
      return(x);//if nth term is 0 or 1 it will return 0 or 1
   }else {
      return(fibonacci(x-1)+fibonacci(x-2));//nth term is sum of its previous two terms
   }
}
int main() {
   int x;
   cout << "Enter nth digit: ";
   cin >> x; 
   cout << " " << fibonacci(x-1);//x-1 because 0 is our 1st term of fibonacci series

   return 0;
}