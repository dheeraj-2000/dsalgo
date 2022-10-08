#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<char> check;
    string exp;
    cout << "Enter the expression :";
    cin >> exp;
    int len = exp.length();
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            check.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (check.top() == '(')
            {
                check.pop();
            }
        }
        else if (exp[i] == ']')
        {
            if (check.top() == '[')
            {
                check.pop();
            }
        }
        else if (exp[i] == '}')
        {
            if (check.top() == '{')
            {
                check.pop();
            }
        }
    }
    if (check.empty() == true)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not balanced";
    }

    return 0;
}
