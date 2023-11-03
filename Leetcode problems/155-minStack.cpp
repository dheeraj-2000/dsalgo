class MinStack
{
public:
    stack<int> st;
    int currMin = 0;

    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            currMin = val;
            st.push(val);
        }
        else
        {
            if (val < currMin)
            {
                st.push(2 * val - currMin);
                currMin = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.top() >= currMin)
            st.pop();
        else
        {
            currMin = 2 * currMin - st.top();
            st.pop();
        }
    }

    int top()
    {
        if (st.top() >= currMin)
            return st.top();
        else
            return currMin;
    }

    int getMin()
    {
        return currMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */