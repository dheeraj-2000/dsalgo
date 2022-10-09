

/*     Approach 1: Using merge-sort technique */
void merge(vector<pair<int ,int  > > &v,int l,int mid,int r,vector<int > &ans){
    int i=l,j=mid,k=0;
    vector<pair<int ,int > > temp(r-l+1);

    while(i<mid && j<=r){
        if(v[i].first<=v[j].first){
            //observe that when this cond^ satisfies then j is incremented
            temp[k++]=v[j++];
        }
        else{
            ans[v[i].second]+=r-j+1; //L-----MID---J-----R R-j will be smaller becuase arrase is beigng sorted in descending order
            temp[k++]=v[i++];
        }
    }
    while(i<mid){
        temp[k++]=v[i++];
    }
    while(j<=r){
        temp[k++]=v[j++];
    }
    k=0;
    for(int i=l;i<=r;i++){
        v[i]=temp[k++];
    }
}

void mergesort(vector<pair<int ,int  > > &v,int i,int j,vector<int> & ans){
    if(i>=j)return ;
    int mid = (i+j)/2;
    mergesort(v,i,mid,ans);
    mergesort(v,mid+1,j,ans);
    merge(v,i,mid+1,j,ans);
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& n) {
        int x=n.size();
        if(x==0)return {};
        vector<int > ans(x,0);
        vector<pair<int ,int > > fi(x);
        for(int i=0;i<x;i++){
            fi[i]=make_pair(n[i],i);
        }
        mergesort(fi,0,x-1,ans);
        return ans;
    }
};



/*     Approach 2: Using Policy Based Data Structure technique */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;


typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


class Solution {
public:
    
    void myerase(pbds &t, int v){
    
        int rank = t.order_of_key(v);
        pbds::iterator it = t.find_by_order(rank); 
        t.erase(it);
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        pbds st;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            st.insert(nums[i]);
        }
        
        vector<int> count(n);
        for(int i = 0 ; i < n ; i++)
        {

            myerase(st, nums[i]);
            
            auto it = st.upper_bound(nums[i]);
            if(it == st.end())
                count[i] = st.size();
            
            else
                count[i] = st.order_of_key(*it);
            
            if(count[i] < 0)
                count[i] = 0;
        }
        
        return count;
        
    }
};
