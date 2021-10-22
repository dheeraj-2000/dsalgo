// CPP code to verify Euclid Euler Theorem
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << "\n";

bool isprime(long long n)
{
	// check whether a number is prime or not
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return false;
}

bool isperfect(long long n) // perfect numbers
{
	// check if n is a perfect sum of divisors
	// except the number itself = number
	long long s = -n;
	for (long long i = 1; i * i <= n; i++) {

		// is i is a divisor of n
		if (n % i == 0) {
			long long factor1 = i, factor2 = n / i;
			s += factor1 + factor2;

			// here i*i == n
			if (factor1 == factor2)
				s -= i;
		}
	}
	return (n == s);
}

int main()
{
	// storing powers of 2 to access in O(1) time
	vector<long long> power2(61);
	for (int i = 0; i <= 60; i++)
		power2[i] = 1LL << i;

	// generation of first few numbers
	// satisfying Euclid Euler's theorem

	cout << "Generating first few numbers "
			"satisfying Euclid Euler's theorem\n";
	for (long long i = 2; i <= 25; i++) {
		long long no = (power2[i] - 1) * (power2[i - 1]);
		if (isperfect(no) and (no % 2 == 0))
			cout << "(2^" << i << " - 1) * (2^("
				<< i << " - 1)) = " << no << "\n";
	}
	return 0;
}
