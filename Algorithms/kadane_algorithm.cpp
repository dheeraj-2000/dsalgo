#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int i=0;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>N;
    int arr[N];
    cout<<"Enter elements of array"<<endl;
    for(i=0;i<N;i++){
        cin>>arr[i];
    }
    int current_sum=0;
    int start,end,s=0;
    int max_sum=0;
    for(i=0;i<N;i++){
        current_sum+=arr[i];
        if(current_sum>max_sum){
            max_sum=current_sum;
            start=s;
            end=i;
        }
        if(current_sum<0){
        current_sum=0;
        s=i+1;
        }
        //max_sum=max(current_sum,max_sum);
    }
    cout<<"Maximum sum in subarray is "<<max_sum<<endl;
    cout<<"Subarray with maximum sum is"<<endl;
    for(i=s;i<=end;i++){
        cout<<arr[i]<<" ";
    }

}