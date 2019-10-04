#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find();
int main(){
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    vector<int>arr;
	    for(int i=0;i<n;i++)
	       arr.push_back(find());
	    cin>>k;
	    sort(arr.begin(),arr.end());
	    cout<<arr[k-1]<<endl;
	}
	return 0;
}

int find(){
    int ret;
    cin>>ret;
    return ret;
}
