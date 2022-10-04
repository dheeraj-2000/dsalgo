//C++ implementation to remove duplicates from a sorted array
//Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

//Function to remove duplicates in an array
int removeNum(int arr[], int num)
{
    // check if the array has 0 or 1 element
    if (num==0 || num==1)
        return num;

    int temp[num];
//Traverse through the array
    int j = 0;
    for (int i=0; i<num-1; i++)

        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];

    temp[j++] = arr[n-1];

    for (int i=0; i<j; i++)
        arr[i] = temp[i];
//Return the length of the new array
    return j;
}

int main()
{
    int arr[] = {10, 20, 20, 30, 40, 40, 40, 50, 50, 80, 90 , 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeNum(arr, n);

    for (int i=0; i<n; i++)
       cout << arr[i] << " ";

    return 0;
}
