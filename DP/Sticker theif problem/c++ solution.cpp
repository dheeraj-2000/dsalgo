// C++ program to find the maximum stolen value
#include <iostream>
using namespace std;

// calculate the maximum stolen value
//n is size of array
//houseVal is our given array
int maxLoot(int *houseVal, int n)
{
	if (n == 0)
		return 0;

	int value1 = houseVal[0];
	if (n == 1)
		return value1;

	int value2 = max(houseVal[0], houseVal[1]);
	if (n == 2)
		return value2;

	// contains maximum stolen value at the end
	int max_val;

	// Fill remaining positions
	for (int i=2; i<n; i++)
	{
		max_val = max(houseVal[i]+value1, value2);
		value1 = value2;
		value2 = max_val;
	}

	return max_val;
}

// Driver to test above code
int main()
{
	// Value of houses
	int houseVal[] = {6, 7, 1, 3, 8, 2, 4};
	int n = sizeof(houseVal)/sizeof(houseVal[0]);
	cout << "Maximum loot possible : "
		<< maxLoot(houseVal, n);
	return 0;
}
