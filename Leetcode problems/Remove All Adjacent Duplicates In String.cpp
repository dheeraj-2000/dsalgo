class Solution {
public:
    string removeDuplicates(string s) {
        if (s.length() == 1)
            return s;
    
        string res;
        stack<char> stack;
        
        for (auto ch: s) {
            if (!stack.empty() && stack.top() == ch) {
                while (!stack.empty() && stack.top() == ch) {
                    stack.pop();
                }
                continue;
            }
            
            stack.push(ch);
        }
        
        res.resize(stack.size());
        
        for (int i = stack.size() - 1; i >= 0; i--) {
            res[i] = stack.top();
            stack.pop();
        }
        
        return res;
    }
};

