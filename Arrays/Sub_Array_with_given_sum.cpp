//C++ implementation to find subarrays with given sum
//Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

//Function to find subarrays with given sum
int ArraySum(int arr[], int n, int sum)
{

    int curr_sum = arr[0], start = 0, i;


    for (i = 1; i <= n; i++) {

        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        if (curr_sum == sum) {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }


        if (i < n)
            curr_sum = curr_sum + arr[i];
    }

    cout << "No subarray found";
    return 0;
}

// Driver Code
int main()
{
    int arr[] = { 5, 12, 24, 78, 49, 35, 20, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    ArraySum(arr, n, sum);
    return 0;
}
