// CPP program to generate 
// Gould's Sequence 
// For more info, refer-> https://en.wikipedia.org/wiki/Gould%27s_sequence
  
#include <bits/stdc++.h> 
using namespace std; 
  
// 32768 = 2^15 
#define MAX 32768 
  
// Array to store Sequence up to 
// 2^16 = 65536 
int arr[2 * MAX]; 
  
// Utility function to pre-compute odd numbers 
// in ith row of Pascals's triangle 
int gouldSequence() 
{ 
  
    // First term of the Sequence is 1 
    arr[0] = 1; 
  
    // Initilize i to 1 
    int i = 1; 
  
    // Initilize p to 1 (i.e 2^i) 
    // in each iteration 
    // i will be pth power of 2 
    int p = 1; 
  
    // loop to generate gould's Sequence 
    while (i <= MAX) { 
  
        // i is pth power of 2 
        // traverse the array 
        // from j=0 to i i.e (2^p) 
  
        int j = 0; 
  
        while (j < i) { 
  
            // double the value of arr[j] 
            // and store to arr[i+j] 
            arr[i + j] = 2 * arr[j]; 
            j++; 
        } 
  
        // upadate i to next power of 2 
        i = (1 << p); 
        // increment p 
        p++; 
    } 
} 
  
// Function to print gould's Sequence 
void printSequence(int n) 
{ 
    // loop to generate gould's Sequence up to n 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
} 
  
// Driver code 
int main() 
{ 
  
    gouldSequence(); 
  
    // Get n 
    int n = 16; 
  
    // Function call 
    printSequence(n); 
  
    return 0; 
} 
