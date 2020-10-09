
#include <iostream>
using namespace std;

// to fing (a^b)%m
int power(int a, unsigned b, unsigned m)
{
    if (!b)
        return 1;
    int res = power(a, b / 2, m) % m;
    res = (res * res) % m;
    if (b % 2 == 0)
        return res;
    return (a * res) % m;
}

// to find gcd
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

void modularInverse(int a, int m)
{
    int gcd_res = gcd(a, m);
    if (gcd_res != 1)
        cout << "The numbers are not co-prime" << endl;
    else
    {
        // modular Inverse = (a^(m-2))%m;
        cout << "Mod inverse: " << power(a, m - 2, m) << endl;
    }
    return;
}

int main()
{
    int a, m;
    cin >> a >> m;
    modularInverse(a, m);
    return 0;
}