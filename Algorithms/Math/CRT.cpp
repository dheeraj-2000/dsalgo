
#include <iostream>
using namespace std;

/* finds gcd and modular inverse of (a, b) using extended euclid's
x is the running a^{-1} (mod b) and y is the running b^{-1} (mod a) 
Runtime: O(log(max(a, b))) */
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

/* Computes an x that satisfies all equivalencies in equivs[]
in their respective mod spaces mods [] using Chinese Remainder Theorem */
void crt(int equivs[], int mods[], int size) {
    int current_total;
    int total_mod = 1;
    int total_value = 0;

    for (int index = 0; index < size; index++) {
        int value = equivs[index];
        int mod = mods[index];

        current_total = 1;
        for (int mod_zero = 0; mod_zero < size; mod_zero++) {
            if (mod_zero != index) {
                current_total *= mods[mod_zero];
            }
        }
        int inverse = modularInverse(current_total, mod);
        if (inverse == -1) {
            return;
        }

        total_value += inverse * value * current_total;
        total_mod *= mod;
 
    }
    cout << total_value % total_mod << endl;
}

/* Computes solution to system of modular congruencies using the Chinese Remainder Theorem
Input format:
Input 1: number of modular equivalencies
Input 2: integer equivalencies a1, a2, ..., am */
int main()
{   
    cout << "Chinese Remainder Theorem: given a list of integer equivalencies {a1, a2, ..., am} "
            "and a list of coprime mod spaces {n1, n2, ..., nm}, "
            "finds an integer x (mod n1 * n2 * ... * nm) "
            "such that x = a1 (mod n1); x = a2 (mod n2); ... x = an (mod nm)." << endl;

    cout << "Enter number of equivalencies:" << endl;
    int size;
    cin >> size;

    int equivs[size];
    int mods[size];

    cout << "Enter equivalencies:" << endl;
    for (int equiv_index = 0; equiv_index < size; equiv_index ++) {
        cin >> equivs[equiv_index]; 
    }

    cout << "Enter mods:" << endl;
    for (int mod_index = 0; mod_index < size; mod_index ++) {
        cin >> mods[mod_index]; 
    }

    crt(equivs, mods, size); 
    return 0;
}