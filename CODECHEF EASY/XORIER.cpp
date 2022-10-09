#include <iostream> 
#include <vector> 
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std; 

int main(){
	int T;
	cin>>T; 
	while(T--){
		int N; 
		cin>>N; 

		vector<int> vec; 
		int inp; 
		for(int i=0; i<N; i++){
			cin>> inp; 
			vec.push_back(inp); 
		}
		long long int count=0; 

		int even=0; int odd=0;   
		vector<int>evenvec; vector<int>oddvec; 
		for(int i=0; i<N; i++){
			if(vec[i]%2==0){
				even++; 
				int val = vec[i]; 
				val = val>>2; //left shift twice
				evenvec.push_back(val); 
			}
			else{
				odd++;
				int val = vec[i]; 
				val = val>>2; 
				oddvec.push_back(val); 
			}
		}
		sort(evenvec.begin(), evenvec.end()); //
		sort(oddvec.begin(), oddvec.end()); //

		int i=0; 
		long long int count_even = 0; 
		for(int j=1; j<even; j++){
			if(evenvec[i]==evenvec[j]){
				//do nothing
			}
			else{
				count_even = count_even + (j-i)*(even-j);
				i=j;
			}
		}
		int p=0; 
		long long int count_odd = 0; 
		for(int q=1; q<odd; q++){
			if(oddvec[q]==oddvec[p]){
				//do nothing
			}
			else{
				count_odd = count_odd + (q-p)*(odd-q);
				p=q;
			}
		}
		count = count_even+count_odd;
		//cout<<count_even<<" "<<count_odd<<endl ;
		cout<<count<<endl ;
	}
return 0; 
}
//lessons: 1. long long int  2. vectors  3. sort_algorithm
