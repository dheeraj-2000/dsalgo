#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {

        ll n, v;
        cin >> n >> v;
        if (n == 1)
        {
            cout << "0 0" << endl;
            continue;
        }
        ll mx = (n * (n - 1)) / 2;
        // ll mx=((n-2)*(n-1))/2+(n-1)*v;
        ll mn = v;
        mn += ((n - v) * (n - v + 1)) / 2;
        mn--;
        if (v >= n)
        {
            cout << mx << " " << n - 1 << endl;
        }
        else
        {
            cout << mx << " " << mn << endl;
        }
    }

    return 0;
}
