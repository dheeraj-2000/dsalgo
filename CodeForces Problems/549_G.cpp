#include <bits/stdc++.h>
#include <list>

#define f first
#define s second
#define pb push_back

using namespace std;

int t, aux, temp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> t;
    int fila[t];

    for(int i = 0; i < t; i ++){
        cin >> aux;
        aux = aux+i;
        fila[i] = aux;
    }

    sort(fila, fila+t);

    for (int i = 0; i < t; i ++)
        fila[i] -= i;

    for (int i = 1; i < t; i ++){
        if(fila[i] < fila[i-1]){
            cout << ":(" << endl;
            return 0;
        }
    }

    for (int i = 0; i < t; i ++)
        cout << fila[i] << " ";
    cout << endl;

    return 0;

}