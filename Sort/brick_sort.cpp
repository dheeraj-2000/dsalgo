/*
    Author:- Akash
    Programme:- A C++ Program to implement Odd-Even  Brick Sort
    Time Compexity:- O(n^2) where, n = Number of elements in the input array
    Space Complexity:-  O(1)
    About:- This is basically a variation of bubble-sort. This algorithm is divided into two phases- Odd and Even Phase.
     The algorithm runs until the array elements are sorted and in each iteration two phases occurs- Odd and Even Phases. 
     It is also known as OddEvensort. 

      */
#include<bits/stdc++.h>
using namespace std;

// A function to sort the algorithm using Odd Even sort
void BrickSort(int arr[], int n)
{
	bool isSorted = false; // Initially array is unsorted

	while (!isSorted)
	{
		isSorted = true;

		// Perform Bubble sort on odd indexed element
		for (int i=1; i<=n-2; i=i+2)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
		}

		// Perform Bubble sort on even indexed element
		for (int i=0; i<=n-2; i=i+2)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
		}
	}

	return;
}



//main function program.
int main()
{
	int n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];

	BrickSort(arr, n);

	for (int i=0; i < n; i++)
    	cout << arr[i] << " ";

	return (0);
}