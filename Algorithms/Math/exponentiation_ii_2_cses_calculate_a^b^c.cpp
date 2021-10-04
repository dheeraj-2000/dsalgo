#include<bits/stdc++.h>
using namespace std;

//==================================Common Shortcuts=====================================

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

// Problem Link : https://cses.fi/problemset/task/1712

// Problem Statement : Calculate a ^ (b ^ c) % (1e9 + 7)

// We know how to calculate a ^ b in least time but what do when a and b are both very large ?  
// When a, b are very large then we may experience overflow so to avoid that we use one property of euler function also called Euler's theroem

// Euler theorem : (a ^ b) % m ≡ (a ^ (b % ϕ(m)) % m
// Read more here : https://cp-algorithms.com/algebra/phi-function.html

// So we have changed the power into modulo, 
// Different perspective of problem : n = b ^ c
// Now problem becomes, 
// (a ^ n) % m ≡ (a ^ (n % ϕ(m)) % m

// For prime numbers ϕ(p) = p - 1, where p is a prime number

// (a ^ (b ^ c)) % m ≡ (a ^ (b ^ c) % ϕ(m)) % m
// Here ϕ(m) = m - 1, since m is prime number

//=============================== Solve ===================================================

ll binpow(ll base, ll power, ll mod) // Calclulates binary exponentitaion (a ^ n) in O (log n) time
{
    ll result = 1;

    while (power)
    {
        if (power % 2) // when power not divisible by 2 then we decreases power by 1 and multiply into the result
        {
            result *= base;
            result %= mod; // doing so to avoid the overflow
            power--;
        }

        else
        {
            base = base * base; // when power is divisible by 2, we halfen the power and multiply it in the base
            base %= mod; // doing so to avoid the overflow
            power /= 2;
        }
    }

    return (result % MOD);
}

void solve()
{
    ll a, b, c, power;
    cin >> a >> b >> c;

    power = binpow(b, c, MOD - 1); // calculating (b ^ c) % ϕ(m) and storing it in power
    cout << binpow(a, power, MOD) << "\n"; // calculating (a ^ (b ^ c) % ϕ(m)) % m
}

//============================== main ====================================================

int main()
{
    fastio();
    ll t;

    t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}

// ============================== End =====================================================