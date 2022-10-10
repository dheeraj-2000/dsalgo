/* Author - Ansh Singh
   Date -  07/10/2021 */

#include<bits/stdc++.h>
using namespace std;

//==================================Common Shortcuts=====================================

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define bs  binary_search
#define lb  lower_bound
#define ub  upper_bound

//======================================Data Types========================================

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

//========================================Debugging Starts=================================

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//==========================================Debugging Ends==========================================

// Problem Link : https://www.spoj.com/problems/PRIME1/cstart=10
// Youtube : https://www.youtube.com/watch?v=khPI7I8H8CM
// Theory : https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes

//=============================== Solve ===================================================

vector <ll> prime; // Global vector now can store upto 1e7

void seive(int sqrtn) // Function to find the number of primes upto sqrt(n), n <= 1e12
{
   int i, j;
   vector <bool> isprime(sqrtn + 1, true); // marking all the numbers from 1 to sqrtn as prime
   isprime[0] = isprime[1] = false; // 1 based indexing, 0 (index) --> 0 (number) , 1 (index) --> 1 (number)

   for (i = 2; i * i <= sqrtn; i++) // outer loop for normal seive
   {
      if (isprime[i])
      {
         for (j = i * i; j <= sqrtn; j = j + i) // marking all the multiple of i, as they won't be prime
         {
            isprime[j] = false;
         }
      }
   }

   for (i = 2; i <= sqrtn; i++) // storing all the primes in prime vector upto sqrt(n)
   {
      if (isprime[i])
         prime.pb(i); // storing prime upto sqrt(n)
   }
}

void solve()
{
   ll m, n, sqrtn, i, j, start;

   cin >> m >> n;
   vector <bool> isprime_m_to_n(n - m + 1, true); // 0 ---> m, 1 ---> m + 1 .... shifting of coordinates sort of

   sqrtn = sqrt(n) + 1; // upperbound of how much primes we want to generate
   seive(sqrtn);

   // debug(prime);

   for (i = 0; i < prime.size(); i++) // iterating in the vector which contains prime from 1 to sqrt(n) + 1
   {
      if (m % prime[i]) // if not divisible we know m is not a multiple of prime[i]
         start = m - m % prime[i] + prime[i]; // start, stores the first occurence of multiple of prime[i] in (m to n)
      else
         start = m;

      // debug(prime[i]);
      // debug(start);

      for (j = start; j <= n; j = j + prime[i]) // marking all the next multiples of prime[i]
      {
         if (j == prime[i]) // carefull !!!!, we don't want to mark the prime[i] if it is in range from m to n
            continue;

         isprime_m_to_n[j - m] = false; // marking all occurences of prime[i] in range m to n, 
         // shifted all numbers from m to n to 0 to n - m (zero based index), 0 (index) ---> m (number) and so on
      }
   }

   for (i = 0; i < (n - m + 1); i++) // now checking numbers in index 0 to m  - n which are prime, if prime, print corresponding number, i.e i + m as we shifted before by m
   {
      if (isprime_m_to_n[i] && (i + m) != 1) // case when i + m == 1, and 1 is not a prime number
         cout << i + m << "\n"; // printing i + m, as we shifted j by m, 0 (index) ---> m (number)
   }

   // debug(isprime_m_to_n);

   cout << "\n";
   prime.clear();
}

//============================== main ====================================================

int main()
{
#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif

   fastio();
   int t;

   t = 1;
   cin >> t;

   while (t--)
   {
      solve();
   }
}

// ============================== End =====================================================