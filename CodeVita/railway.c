#include<iostream>
#include<algorithm>
using namespace std;

// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n)
{
   // Sort arrival and departure arrays
   sort(arr, arr+n);
   sort(dep, dep+n);

   // plat_needed indicates number of platforms needed at a time
   int plat_needed = 1, result = 1;
   int i = 1, j = 0;

   // Similar to merge in merge sort to process all events in sorted order
   while (i < n && j < n)
   {
      // If next event in sorted order is arrival, increment count of platforms needed
      if (arr[i] <= dep[j])
      {
          plat_needed++;
          i++;

          // Update result if needed
          if (plat_needed >= result)
              result = plat_needed;
      }

      // Else decrement count of platforms needed
      else
      {
          plat_needed--;
          j++;
      }
   }

   return result;
}

// Driver program to test methods of graph class
int main()
{
    int arr[] = {2, 6};
    int dep[] = {4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}
