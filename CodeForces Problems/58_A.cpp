#include <bits/stdc++.h>
using namespace std;
string a, b = "hello";
int j = 0, pas = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[j]) {
            j++;
            if (j == 5) {
                break;
            }
        }
    }
    if (j == 5) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}