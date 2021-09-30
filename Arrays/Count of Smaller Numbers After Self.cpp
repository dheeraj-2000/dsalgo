
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
