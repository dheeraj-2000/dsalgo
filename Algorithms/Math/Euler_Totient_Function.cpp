
//Euler’s Totient function F(n) for an input n is the count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.

//For example, F(4) = 2, F(3) = 2 and F(5) = 4. There are 2 numbers smaller or equal to 4 that are relatively prime to 4, 2 numbers smaller or equal to 3 that are relatively prime to 3. And 4 numbers smaller than or equal to 5 that are relatively prime to 5.
#include <stdio.h>

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// A simple method to evaluate Euler Totient Function
int phi(unsigned int n)
{
	unsigned int result = 1;
	for (int i = 2; i < n; i++)
		if (gcd(i, n) == 1)
			result++;
	return result;
}

// Driver program to test above function
int main()
{
	int a;
	scanf("%d",&a);
	for (int n = 0; n <= a; n++)
		printf("phi(%d) = %d\n", n,  phi(n));
	return 0;
}

