#include<iostream>
#include<climits>
using namespace std;
//Boolean function isPossible
 bool isPossible(int a[],int n,int m,int min_curr){
     int studentUsed=1;
     int readPages=0;

     for(int i=0;i<n;i++){
         if(readPages +a[i] >min_curr){
             studentUsed++;
             readPages=a[i];
             if(studentUsed>m){
                 return false;
             }
         }
         else{
             readPages +=a[i];
         }
     }
     return true;
 }

 //Binary search ssolution  for the given given problem
int findPages(int a[],int n,int m){
        if(n<m){
        return -1;
        }
        long long sum=0;
        for(int i=0;i<n; i++){
            sum +=a[i];
        }
        int ans=INT_MAX;
        int s=a[n-1];
        int e=sum;
        while(s<=e){
            int  mid=s+e>>1;
            if(isPossible(a,n,m,mid)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }

        }
        return ans;        
}
int main(){

    int test;
    cin>>test;
    for(int i=0; i<test; i++){
        int n,m;
        cin>>n>>m;
        int books[1000];
   
    for(int j=0; j<n; j++){
        cin>>books[j];
    }
    cout<<findPages(books,n,m);
    }
    return 0;
}