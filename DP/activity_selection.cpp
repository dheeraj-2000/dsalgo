#include <bits/stdc++.h> 
using namespace std; 

int activitySelection(vector<int> start, vector<int> end, int n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<n; i++){
        pq.push(make_pair(end[i], start[i]));
    }
        
    int count=1, prev=pq.top().first;
    
    while(!pq.empty()){
        if(pq.top().second>prev){
            prev=pq.top().first;
            count++;
        }
        
        pq.pop();
    }
        
    return count;
}

int main() 
{ 
	int n;
	cin>>n;
	
	vector<int> start(n), end(n);
	for(int i=0; i<n; i++){
	    cin>>start[i];
	    cin>>end[i];
	}
	
	cout<<activitySelection(start, end, n);
	return 0; 
} 
