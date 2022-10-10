#include <bits/stdc++.h>
using namespace std;
void diceRoll(string pro, int target)
{
    if (target == 0)
    {
        cout << pro << " ";
        return;
    }
    for (int i = 1; i <= 6 and i <= target; i++)
    {
        diceRoll(pro + to_string(i), target - i);
    }
    return;
}
int main()
{
    diceRoll("", 4);
    return 0;
}
