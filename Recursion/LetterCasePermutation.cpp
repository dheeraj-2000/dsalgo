#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


//siddhartha v

void solve(int index,int max,string s,string ds,vector<string> &ans)
{
	if(index>=max)
	{
		ans.push_back(ds);
		return ;
	}
	if(s[index]>='0' && s[index]<='9')
	{
		ds.push_back(s[index]);
		solve(index+1,max,s,ds,ans);
	}
	else{
		
		ds.push_back(tolower(s[index]));
		solve(index+1,max,s,ds,ans);
		ds.pop_back();
		ds.push_back(toupper(s[index]));
		solve(index+1,max,s,ds,ans);
	}
	
	
}

vector<string> letterCasePermutation(string s) {
	
	string ds;
	vector<string> ans;
	int max = s.size();
	solve(0,max,s,ds,ans);
	return ans;        
}
int main()
{
	vector<int> v;
	
}