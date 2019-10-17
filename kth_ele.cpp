#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int search();
int main(){
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    vector<int>arr;
	    for(int i=0;i<n;i++)
	       arr.push_back(search());
	    cin>>k;
	    sort(arr.begin(),arr.end());
	    cout<<arr[k-1]<<endl;
	}
	return 0;
}

int search(){
    int ret;
    cin>>ret;
    return ret;
}
