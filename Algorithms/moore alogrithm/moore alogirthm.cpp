#include <stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int size,count=1,id=0;
    cout<<"enter the size of an array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"enter the number of element"<<endl;
    for(int i =0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i =1;i<size;i++)
    {
        if(arr[i]==arr[id])
        {
            count++;
        }
        else
        count--;
        if(count==0)
        {
            id=i;
            count=1;
        }
    }
    cout<<"the maximum number of element occured is"<<endl;
    cout<<arr[id];
    

    return 0;
}

Time complexity-O(n) and space complexity-O(1)
