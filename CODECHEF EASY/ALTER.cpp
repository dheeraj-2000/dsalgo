#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, p, q;
        cin >> a >> b >> p >> q;
        int x, y;
        if (p % a != 0 || q % b != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            x = p / a;
            y = q / b;
            if (y - x == 1 || x - y == 1 || y - x == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
