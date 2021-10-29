#include <bits/stdc++.h>
using namespace std;

int solve(int index, int k, vector<int> &v)
{
    if (v.size() == 1)
    {
        return v[0];
    }

    index = (index + k) % v.size(); // k-1 is done for zero based indexing

    v.erase(v.begin() + index);

    return solve(index, k, v);
}

int safePos(int n, int k)
{
    vector<int> v;
    // Prepare a vector where each element is its respective index value
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    return solve(0, k - 1, v); // starting from 0th position
}

int main()
{
    int n, k;
    cin >> n >> k;

    int safe_position = safePos(n, k);

    cout << "The safe position will be :" << safe_position << '\n';

    return 0;
}