// A Dynamic Programming based
// solution that uses
// table dp[][] to calculate
// the Binomial Coefficient
// A naive recursive approach
// with table C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeffUtil(int n, int k, int** dp)
{
	// If value in lookup table then return
	if (dp[n][k] != -1) //	
		return dp[n][k];

	// store value in a table before return
	if (k == 0) {
		dp[n][k] = 1;
		return dp[n][k];
	}
	
	// store value in table before return
	if (k == n) {
		dp[n][k] = 1;
		return dp[n][k];
	}
	
	// save value in lookup table before return
	dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) +
			binomialCoeffUtil(n - 1, k, dp);
	return dp[n][k];
}

int binomialCoeff(int n, int k)
{
	int** dp; // make a temporary lookup table
	dp = new int*[n + 1];

	// loop to create table dynamically
	for (int i = 0; i < (n + 1); i++) {
		dp[i] = new int[k + 1];
	}

	// nested loop to initialise the table with -1
	for (int i = 0; i < (n + 1); i++) {
		for (int j = 0; j < (k + 1); j++) {
			dp[i][j] = -1;
		}
	}

	return binomialCoeffUtil(n, k, dp);
}

/* Driver code*/
int main()
{
	int n = 5, k = 2;
	cout << "Value of C(" << n << ", " << k << ") is "
		<< binomialCoeff(n, k) << endl;
	return 0;
}

// This is code is contributed by MOHAMMAD MUDASSIR
