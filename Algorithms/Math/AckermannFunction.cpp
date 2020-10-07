/* Ackermann Function is defined as,
                      __   
                     |   n+1  ,if m=0
    ackermann(m,n) = |   ackermann(m-1,1)   ,if m>0 and n=0
                     |__ ackermann(m-1,ackermann(m,n-1))    ,if m>0 and n>0

                            Here, m and n are non-negative integers
                      
                      Time Complexity: O(m ackermann(m,n))
                      Space Complexity: O(m)
                      */

#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    if (!m)
        return n + 1;
    else if (m > 0 and n == 0)
        return ackermann(m - 1, 1);
    else if (m > 0 && n > 0)
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    int result, m, n;
    cin >> m >> n;
    result = ackermann(m, n);
    cout << result << endl;
    return 0;
}