// Problem - Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector <int> &array, int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + array[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int main(){
	int length_of_array,k;

	cin >> length_of_array;

	vector <int> array;

	for(int counter = 0 ; counter < length_of_array ; counter++){
		cin >> k;
		array.push_back(k);
	}

	cout << maxSubArraySum(array,length_of_array) << endl;

}