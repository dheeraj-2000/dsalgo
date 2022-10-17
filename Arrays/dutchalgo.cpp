#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void dutch(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
            mid++;
        }
    }
    print(arr,n);
}

int main()
{
    int arr[] = {0, 1, 0, 0, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    dutch(arr, n);
}