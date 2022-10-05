
/*
Catalan numbers is a number sequence, which is found useful in a number of
combinatorial problems, often involving recursively-defined objects.
*/
//Finding Catalan numbers using dynamic programming
/* Time Complexity: O(n^2)
Space Complexity: O(n) */

#include <iostream>
using namespace std;

// Finding the n_th catalan number
unsigned long findCatalan(unsigned n)
{
    unsigned long catalan[n+1];    //array of catalan numbers
    catalan[0]=catalan[1]=1;       //initializing first two catalan numbers

    //filling the catalan array using recursion
    for (int i=2;i<=n;i++) {
        catalan[i]=0
        for (int j=0;j<i;j++)
            catalan[i]+=catalan[j]*catalan[i-j-1];
    }

    return catalan[n];
}

int main()
{
    unsigned n;
    cin >> n;
    for (unsigned i = 0; i < n; i++)
        cout << findCatalan(i) << endl;
    return 0;
}
