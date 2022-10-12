#include<bits/stdc++.h>
using namespace std;
int frogcost(vector<int>&nums,int currentidx,unordered_map<int,int>&mp){
	if(currentidx==nums.size()-1){
		return 0;
	}
	if(currentidx>nums.size()-1){
		return 10001;
	}
	int currentkey=currentidx;
	if(mp.find(currentkey)!=mp.end()){
		return mp[currentkey];
	}
	int onejump=frogcost(nums,currentidx+1,mp)+abs(nums[currentidx]-nums[currentidx+1]);
	int twojump=frogcost(nums,currentidx+2,mp)+abs(nums[currentidx]-nums[currentidx+2]);
	mp[currentkey]=min(onejump,twojump);
	return mp[currentkey];
}
int main(){
	unordered_map<int,int>mp;
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<nums.size();i++)
		cin>>nums[i];
	
	int cost=frogcost(nums,0,mp);
	cout<<cost;
}
