#include<iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void DNFsort(int arr[], int n)
{
    int low,mid,high;
    low = 0;
    mid = 0;
    high = n-1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr,low,mid);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr,high,mid);
            high--;
        }
    }
}

int main()
{
    int arr[] = {1,0,2,1,0,1,2,1,2};
    int s = sizeof(arr)/sizeof(int);

    DNFsort(arr,s);

    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}