/* Sieve of Eratosthenes is an algorithm for finding all prime numbers up to any given limit.
    It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with
    the first prime number, 2. The multiples of a given prime are generated as a sequence of numbers starting from that prime,
    with constant difference between them that is equal to that prime. */

/* The time complexity of the algorithm is O(n*lg(lg(n))) */

/* Input: 15
   Output: 2,3,5,7,11,13 */

#include <iostream>
using namespace std;

void findPrimes(bool isPrime[], int n)
{
    // 1 denotes that the number is a prime number
    // 0 denotes that the number is composite
    isPrime[2] = 1; // 2 is a prime number (the only even prime number)

    // put 1 at all odd positions
    for (int i = 3; i < n; i += 2)
        isPrime[i] = 1;

    // making all multiples of odd numbers as composite
    for (int i = 3; i < n; i += 2)
    {
        //Check prime(i.e, 1){
        if (isPrime[i] == 1)
        {
            //Make all multiples of i as composite
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    return;
}

int main()
{

    int n;
    cout << "Enter the number upto which primes numbers are to be found: ";
    cin >> n;
    bool isPrime[n + 1] = {0};
    findPrimes(isPrime, n);
    for (int i = 2; i < n; i++)
        if (isPrime[i])
            cout << i << ' ';
    cout << endl;
    return 0;
}