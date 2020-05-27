// Fibonacci numbers are the numbers in the following integer sequence. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
// @dheeraj

#include<iostrem>
using namespace std;




// Driver Code
int main() {
      /* code */
      int n;
      cout <<"Enter the nth term: ";
      cin>>n;
      cout<<n<<"th Fibonacci number is: "<<getnth_fibonaacci(n);
      return 0;
}
