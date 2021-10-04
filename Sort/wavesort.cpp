/* asked in interview */
#include<iostream>
using namespace std;

void wavesort(int arr[], int n)
{
    int i = 1;
    while (i <= n+1)
    {
        if(arr[i] > arr[i-1])
        {
            swap(arr[i], arr[i-1]);
        }

        if(arr[i] > arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }

        i += 2;
    }
    
}

int main()
{
    int arr[] = {1,3,4,7,5,6,2};

    int s = sizeof(arr)/sizeof(int);

    wavesort(arr,s);

    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}