#include <bits/stdc++.h>
using namespace std;
#define MAX 11

vector<int> Sieve()
{
    vector <int> res;
    bool primes[MAX+1];
    memset(primes,true, sizeof(primes));

    for(int p=2; p*p<=MAX; p++)
    {
        if(primes[p])
        {
            for(int i=p*p; i<=MAX; i+=p)
            {
                primes[i] = false;
            }
        }
    }

    for(int i=2; i<=MAX; i++)
    {
        if(primes[i])
            res.push_back(i);
    }

    return res;
}
int main()
{
    vector <int> res = Sieve();
   
    for(int i: res)
        cout<<i<<endl;
    
    return 0;
}