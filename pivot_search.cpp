#include <bits/stdc++.h>
using namespace std;
int getpivot(int arr[],int n)
{
  int s=0;
  int e=n-1;
  int mid=s+(e-s)/2;
  while(s<e)
    {
      if(arr[mid]>=arr[0])
      {
        s=mid+1;
      }
      else
      {
        e=mid;
      }
      mid=s+(e-s)/2;
    }
  return s;
}
int main() {
  vector<int> arr;
  int n;
  cout<<"Enter the size of the array : ";
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
  int key;
  cout<<"Enter element to be searched : ";
  cin>>key;
  int pivot=getpivot(arr,6);
  if(arr[pivot]>key)
  int pos=binary_search(arr.begin(),arr+pivot,key);
  else pos=binary_search(arr+pivot,arr.end());
  if(pos==-1)
  {
    cout<<"Element not found!";
  }
  else
  {
    cout<<"Element found at index "<<pos;
  }
  return 0;
}