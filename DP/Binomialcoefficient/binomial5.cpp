// C++ program for the above approach
#include<bits/stdc++.h>
using namespace std;

// Function to find binomial
// coefficient
int binomialCoeff(int n, int r)
{

	if (r > n)
		return 0;
	long long int m = 1000000007;
	long long int inv[r + 1] = { 0 };
	inv[0] = 1;
	if(r+1>=2)
	inv[1] = 1;

	// Getting the modular inversion
	// for all the numbers
	// from 2 to r with respect to m
	// here m = 1000000007
	for (int i = 2; i <= r; i++) {
		inv[i] = m - (m / i) * inv[m % i] % m;
	}

	int ans = 1;

	// for 1/(r!) part
	for (int i = 2; i <= r; i++) {
		ans = ((ans % m) * (inv[i] % m)) % m;
	}

	// for (n)*(n-1)*(n-2)*...*(n-r+1) part
	for (int i = n; i >= (n - r + 1); i--) {
		ans = ((ans % m) * (i % m)) % m;
	}
	return ans;
}

/* Driver code*/
int main()
{
	int n = 5, r = 2;
	cout << "Value of C(" << n << ", " << r << ") is "
		<< binomialCoeff(n, r) << endl;
	return 0;
}
