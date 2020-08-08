#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<double> Trains;

int minPlatforms(Trains arrival, Trains departure)
{
	int count = 0;
	int platforms = 0;

	int i = 0, j = 0;

	while (i < arrival.size())
	{
		if (arrival[i] < departure[j])
		{
			platforms = max(platforms, ++count);

			i++;
		}

		else
			count--, j++;
	}

	return platforms;
}

// Find minimum number of platforms needed in the station to avoid any
// delay in arrival of any train
int main()
{
	Trains arrival =	{ 2.00, 2.10, 3.00, 3.20, 3.50, 5.00 };
	Trains departure = { 2.30, 3.40, 3.20, 4.30, 4.00, 5.20 };

	// sort arrival time of trains
	sort(arrival.begin(), arrival.end());

	// sort departure time of trains
	sort(departure.begin(), departure.end());

	cout << "Minimum platforms needed is " <<
			minPlatforms(arrival, departure);

	return 0;
}
