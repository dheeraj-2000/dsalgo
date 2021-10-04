#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=================================

vi g[N];
int a[N];

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}

//  ======================================================================

// Solution Approach:
/*
The main idea of solution is,
When we select a backspace for input at that time, we lose 
two characters: one that was previously input and the character 
that the backspace removes (last char before it (if string is empty 
then no char. will remove))

So, starting with the last (right to left) char. of s and t, 
we point two pointers to the last char and compare S(i1) and T(j-1) 
in the following step if they match, else we compare S(i-2) with T(j) 
and process it until either PS >=0 OR PT >= 0 (PS and PT are pointers (index)).

If the length of the match characters equals the length of T, the answer is "YES".

Please see the code below for a better understanding.
*/

//  ======================================================================

void solve()
{
    string s, t;
    cin >> s >> t;

    int len_s = s.length(), len_t = t.length();
    int pt = len_t - 1, ps = len_s - 1;
    int match_char = 0;

    if (len_s < len_t)
    {
        cout << "NO\n";
        return;
    }

    for (; (ps >= 0) && (pt >= 0);)
    {
        if (s[ps] == t[pt])
        {
            ps--, pt--;
            match_char++;
        }
        else
            ps -= 2;
    }

    if ((match_char == len_t) && match_char != 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, i, j, k, p, q, r, x, y, u, v, n, m;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}