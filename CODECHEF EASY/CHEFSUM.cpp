#include <iostream>
using namespace std; 

int main(){
	
	int min, T; 
	cin>>T;
	while(T-->0){
	
	int N,index;
	index=0;
	min=100001 ;
	cin>>N;
	int a[N];
	
	for (int i=0; i<N; i++){
		cin>>a[i];
		if (a[i]<min){min=a[i]; index=i+1;}
	}
	cout<<index<<endl;
	}
}
