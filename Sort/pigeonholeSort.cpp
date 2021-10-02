/*
Pigeon Hole algorithm is a good algorithm to use when the number of elements is of the same order as the amount of possible key values
*/


#include <bits/stdc++.h> 
using namespace std; 

void pigeonholeSort(int arr[], int n) { 
   
    int min = arr[0], max = arr[0]; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    int range = max - min + 1;
    vector<int> holes[range]; 

    for (int i = 0; i < n; i++) {
        holes[arr[i]-min].push_back(arr[i]); 
    }
        
    int index = 0;
    for (int i = 0; i < range; i++) {
       for (auto it = holes[i].begin(); it != holes[i].end(); ++it) 
            arr[index++]  = *it; 
    } 
} 

int main() { 
    int arr[] = {100,59,58,57,56,55,54}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    pigeonholeSort(arr, size); 
    for (int i = 0; i < size; i++) 
        cout<< arr[i]<<" ";
    return 0; 
}