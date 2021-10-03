/*---------koolgax99---------------*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 1; i <= n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    ll int t, i, j, k, p, q = 1, r, x, y, u, v, n, m;
    cin >> t;
    while (t--)
    {
        ll int q = 1;
        cin >> p;

        fo(i, p)
        {
            q = q * i;
        }

        cout << q << endl;
    }
    return 0;
}
