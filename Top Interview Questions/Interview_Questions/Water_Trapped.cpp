
//Time Complexity: O(n). 

//Space Complexity: O(n). 


#include<bits/stdc++.h>
using namespace std;
 

int maximum_Water(int array[], int a)
{
     
    // To store the maximum water
    int stored_water = 0;
     
    // For each element of the array
    for (int p = 1; p < a-1; p++) {
         
        // Find the maximum element on its left side of the array
        int left_of_array = array[p];
        for (int q=0; q<p; q++)
           left_of_array = max(left_of_array, array[q]);
         
        // Find the maximum element on its right side of the array 
        int right_of_array = array[p];
        for (int q=p+1; q<a; q++)
           right_of_array = max(right_of_array, array[q]);
        
       // Update it  
       stored_water = stored_water + (min(left_of_array, right_of_array) - array[p]);  
    }
 
    return stored_water;
}
 

int main()
{
    int array[] = {4,2,0,3,2,5};
    int a = sizeof(array)/sizeof(array[0]);
     
    cout << maximum_Water(array, a);
     
    return 0;
}