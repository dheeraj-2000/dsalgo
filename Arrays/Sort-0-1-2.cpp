// Statement
Given an array of 0,1 and 2 sort them in a manner that 0 appears on left side, 1 in middle
and 2 on right side.

// Exmaple:-
Input:- [0,2,0,2,1,2,1,1]
Output:- [0,0,1,1,1,2,2,2]

#include <bits/stdc++.h> 
void sort012(int *arr, int n){

    // Using a 3-pointer approach
    int currIndex = 0;
    int left = 0,right = n - 1;
    
    
    while (currIndex <= right){
        // Curr index targets on sorting the numbers where as the Left and Right act as the referencing variables.
        
        if (arr[currIndex] == 0){
            swap(arr[currIndex], arr[left]);
            currIndex++;
            left++;
        }
        
        // arr[currIndex] == 1 ==> now the currindex is at the index between the left and right we just need to increment currIndex
        else if (arr[currIndex] == 1)
            currIndex++;
            
        // arr[currIndex]==2 ==> the value should be shifted to the right hand side.
        else{
            swap(arr[currIndex], arr[right]);
            right--;
        }
    }
}

// The Space Complexity is O(1). as 3 variables are created
// The Worst Case Time Complexity is O(n) in the case when the array is already sorted.
