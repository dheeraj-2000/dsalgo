
int merge(vector<int > &v,int l,int mid,int r){
    int i=l,j=mid,k=0,c=0;
    int temp[r-l+1];
    for(int it=l;it<=mid-1;it++){
        while(j<=r && v[it]>(2LL*v[j])){
            j++;
        }
        c+=(j-mid);
    }
    j=mid;
    while(i<mid && j<=r){
        if(v[i]<=v[j]){
            temp[k++]=v[i++];
        }
        else{
            temp[k++]=v[j++];
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
    return c;
}

int  mergesort(vector<int > &v,int i,int j){
    if(i>=j)return 0;
    int d=0;
    int mid = (i+j)/2;
    d=mergesort(v,i,mid);
    d+=mergesort(v,mid+1,j);
    d+=merge(v,i,mid+1,j);
    
    return d;
}

class Solution {
public:
    int reversePairs(vector<int>& n) {
        int x=n.size();
        if(x==0)return 0;
        int ans=mergesort(n,0,x-1);
        return ans;
    }
};
