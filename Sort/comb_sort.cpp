// Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always compares adjacent values. So all inversions are removed one by one. Comb Sort improves on Bubble Sort by using gap of size more than 1. The gap starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1. Thus Comb Sort removes more than one inversion counts with one swap and performs better than Bubble Sort.
// C++ implementation of Comb Sort
#include<bits/stdc++.h>
using namespace std;

// To find gap between elements
int getNextGap(int gap)
{
	// Shrink gap by Shrink factor
	gap = (gap*10)/13;

	if (gap < 1)
		return 1;
	return gap;
}

// Function to sort a[0..n-1] using Comb Sort
void combSort(int array[], int n)
{
	// Initialize gap
	int gap = n;

	// Initialize swapped as true to make sure that
	// loop runs
	bool swapped = true;

	// Keep running while gap is more than 1 and last
	// iteration caused a swap
	while (gap != 1 || swapped == true)
	{
		// Find next gap
		gap = getNextGap(gap);

		// Initialize swapped as false so that we can
		// check if swap happened or not
		swapped = false;

		// Compare all elements with current gap
		for (int i=0; i<n-gap; i++)
		{
			if (array[i] > array[i+gap])
			{
				swap(array[i], array[i+gap]);
				swapped = true;
			}
		}
	}
}

// Driver program
int main()
{
	int array[] = {83, 938 ,-285 ,930 , 4, 034, 3849 , 0 , -94 , 739 , 56};
	int n = sizeof(array)/sizeof(array[0]); 

	combSort(array, n);

	printf("Sorted array: \n");
	for (int i=0; i<n; i++)
		printf("%d ", array[i]);

	return 0;
}
