// Greatest Common Divisor Algorithm in recursive approach

#include<bits/stdc++.h>
using namespace std;

int gcd(int firstNum, int secondNum) {
	// firstNum%secondNum = secondNum;
	// when secondNum divides completely to the firstNum 
	// firstNum%secondNum = remainder 
	if(firstNum%secondNum==0){
		return secondNum;
	}
    return gcd(secondNum,firstNum%secondNum);
}

int main(){
  int firstnum , secondnum;
  cin>>firstnum>>secondnum;
  cout<<gcd(firstnum,secondnum);

  return 0;
}
