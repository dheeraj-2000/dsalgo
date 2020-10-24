class Solution
{
public:
    void solve(vector<string> &s, int o, int c, int n, string op)
    {
        if (c == 0 && o == 0)
        {
            s.push_back(op);
            return;
        }
        if (o != 0)
        {
            string op1 = op;
            op1.push_back('(');
            solve(s, o - 1, c, n, op1);
        }
        if (c > o)
        {
            string op2 = op;
            op2.push_back(')');
            solve(s, o, c - 1, n, op2);
            return;
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> s;
        string op = "";
        int c = n;
        int o = n;
        solve(s, o, c, n, op);
        return s;
    }
};