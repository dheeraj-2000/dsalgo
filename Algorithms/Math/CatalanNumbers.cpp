
/*
Catalan numbers is a number sequence, which is found useful in a number of
combinatorial problems, often involving recursively-defined objects.
*/

/* Time Complexity: O(2^n)
Space Complexity: O(1) */

#include <iostream>
using namespace std;

// Finding the n_th catalan number
unsigned long findCatalan(unsigned n)
{
    if (n <= 1)
        return 1;
    unsigned long result = 0;
    for (int i = 0; i < n; i++)
        result = result + findCatalan(i) * findCatalan(n - i - 1);
    return result;
}

int main()
{
    unsigned n;
    cin >> n;
    for (unsigned i = 0; i < n; i++)
        cout << findCatalan(i) << endl;
    return 0;
}