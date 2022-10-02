// Statement
Given an array of 0,1 and 2 sort them in a manner that 0 appears on left side, 1 in middle
and 2 on right side.

// Exmaple:-
Input:- [0,2,0,2,1,2,1,1]
Output:- [0,0,1,1,1,2,2,2]

#include <bits/stdc++.h> 
void sort012(int *arr, int n){
    int currIndex = 0;
    int left = 0,right = n - 1;
    while (currIndex <= right){
        if (arr[currIndex] == 0){
            swap(arr[currIndex], arr[left]);
            currIndex++;
            left++;
        }
        else if (arr[currIndex] == 1)
            currIndex++;
        else{
            swap(arr[currIndex], arr[right]);
            right--;
        }
    }
}
