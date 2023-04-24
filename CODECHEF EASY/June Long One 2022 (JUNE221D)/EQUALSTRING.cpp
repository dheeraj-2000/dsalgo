#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n, step=0;
	    string str1, str2;
	    cin>>n;
	    cin>>str1>>str2;
	    for(int i=0; i<n; i++) {
	        if(str2[i]==str1[i])
	            continue;
	        for(int j=i; j<n; j++) {
	            char ch = str2[i];
	            if(str2[j]==ch && str1[j]!=ch)
	                str1[j] = ch;
	        }
	        step++;
	    }
	    cout<<step<<endl;
	}
	
	return 0;
}