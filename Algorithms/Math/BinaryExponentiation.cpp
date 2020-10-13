/*  This algorithm allows us to calculate a^n in O(lg(n)) time.  */

#include <iostream>
using namespace std;

long long binaryExponentiation(int a, int n)
{
    if (!n) // Base case
        return 1;
    long long result = binaryExponentiation(a, n / 2);
    if (n % 2)
        return result * result * a;
    else
        return result * result;
}

int main()
{
    int a, n;
    cin >> a >> n;
    if (n < 0)
        cout << "Enter positive exponent." << endl;
    else if (a == 0 && n == 0)
        cout << "Not defined." << endl;
    else
    {
        long long result = binaryExponentiation(a, n);
        cout << result << endl;
    }
    return 0;
}