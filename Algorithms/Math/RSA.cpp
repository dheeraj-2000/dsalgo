
#include <iostream>
using namespace std;

// to find (a^b)%m (copied from fermat's)
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

// finds gcd and modular inverse
int egcd(int a, int b, int* x, int* y)
{
    if (!b) {
        *x = 1;
        *y = 0;
        return a;
    }
    int gcd_res =  egcd(b, a % b, x, y);
    int temp = *x;
    *x = *y;
    *y = temp - ((a/b) * (*y)); 
    return gcd_res;
}

// find modular inverse of a (mod m) if gcd(a,m) == 1
int modularInverse(int a, int m)
{
    int inverse;
    int x = 0;
    int y = 0;
    int gcd_res = egcd(a, m, &x, &y);
    if (gcd_res != 1) {
        cout << "The numbers are not co-prime" << endl;
        return -1;
    } else {
        if (x < 0) {
            x += m;
        }
        return x;
    }
}

/* Find the encyrption and decryption of message where
Public key = (N,e) and private key = d */
void rsa(int p, int q, int e, int message) {
    if (p <= 1 || q <= 1 || p == q) {
        cout << "p and q must be distinct positive primes";
    }

    int n = p*q;
    int lambda = (p-1) * (q-1);
    int d = modularInverse(e, lambda);
    if (d == -1) {
        return;
    }
    cout << "d: " << d << endl;

    int encryption = power(message, e, n);
    cout << "Encryption: " << encryption << endl;
    int decryption = power(encryption, d, n);
    cout << "Decryption: " << decryption << endl;
}

int main()
{   
    cout << "Public key = (N, e) where N = pq, p and q are distinct primes, and e is coprime with (p-1)(q-1). Input format: p q e message" << endl;
    int p, q, e, message;
    cin >> p >> q >> e >> message;
    rsa(p, q, e, message);
    return 0;
}