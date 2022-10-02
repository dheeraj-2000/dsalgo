#include <bits/stdc++.h>
using namespace std;
// using variable for open and close counts
void findParenthesis(vector<string> &res, string str, int open, int close, int n)
{
    if (open == n and close == n)
    {
        res.push_back(str);
        return;
    }
    if (open < n)
        findParenthesis(res, str + '(', open + 1, close, n);

    if (close < open) // run this only when open are more then close,obvious thing
        findParenthesis(res, str + ')', open, close + 1, n);
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    // generator(result, "(", n);
    findParenthesis(result, "", 0, 0, n);
    return result;
}
int main()
{
    vector<string> res = generateParenthesis(3);
    for (auto i : res)
        cout << i << " ";
    return 0;
}
