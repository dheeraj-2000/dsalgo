// Code added by-:Daksh Lakhotiya
// LinkedIn-:https://www.linkedin.com/in/daksh-lakhotiya-36008b190/


#include<bits/stdc++.h>
using namespace std;

//Seive Of Eratosthenes -: It is the algorithm to print all prime numbers till n.

void Seive_Of_Eratosthenes(int n){
	int arr[n] = {0};
	
	for(int i = 2; i < n; i++){
		if(arr[i] == 0){
			for(int j = i*i; j <= n; j+=i){
				arr[j] = 1;
			}
		}
	}
	for(int i = 2; i < n; i++){
		if(arr[i] == 0){
			cout<<i<<" ";
		}
	}cout<<endl;

} 
 // Prime factorisation of a number n using seive of eratosthenes.
void primefactor(int n){
	int arr[n] = {0};

	for(int i = 2; i <= n; i++){
		arr[i] = i;
	}

	for(int i = 2; i <= n; i++){
		if(arr[i] == i){
			for(int j = i*i; j <=n; j+=i){
				if(arr[j] == j){
					arr[j] = i;
				}
			}
		}
	} 

	while(n != 1){
		cout<<arr[n]<<" ";
		n = n/arr[n];
	}
}


int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Prime numbers till " << n << " are:-" << endl;
    Seive_Of_Eratosthenes(n);
    cout<<"Prime factorisation of " << n << " is-:" << endl;
	primefactor(n);

	return 0;
}