#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void oreo()
{
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    int f[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        f[b] = 1;
    }
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {
            ct = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ct != i)
        {
            cout << ct << " " << i << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        oreo();
    }

    return 0;
}