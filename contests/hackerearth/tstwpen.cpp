// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//    long long int l,c,p;
//     cin>>l>>c;
//     p = l-1+c;
//     cout<< p<<endl;
//   }
// }
#include <iostream>
using namespace std;

int main() {
	// your code goes here
  long long	int t;
	cin>>t;
	while(t--){
	    long long int a,b,max,min;
	    cin>>a>>b;
      if(a>b){
  	max=a;
  	min=b;}
  else{
  	max=b;
  	min=a;}
	    cout<<max+min-1<<" "<<max-min+1<<endl;
	}
	return 0;
}
