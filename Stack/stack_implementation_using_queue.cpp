//implement stack using two queues

#include <iostream>
#include<queue>
#include<vector>
#include <cstdlib>

using namespace std;

//stack class
class Stack{

    queue<int> q1, q2;
 
public:
    // Insert an items into the stack
    void push(int data)
    {
        // Move all elements from the first queue to the second queue
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
 
        // Push the given items into the first queue
        q1.push(data);
 
        // Move all elements back to the first queue from the second queue
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
        
    // Remove the top items from the stack
    int pop()
    {
        // if the first queue is empty
        if (q1.empty())
        {
            cout << "queue is empty";
            exit(0);
        }
 
        // return the front items from the first queue
        int front = q1.front();
        q1.pop();
 
        return front;
    }
};

int main()
{
    vector<int> items = { 13, 6, 7, 9, 10 };
 
    // insert the above items into the stack
    Stack s;
    for (int item: items) {
        s.push(item);
    }
 
    for (int i = 0; i <= items.size(); i++) {
        cout << s.pop() << endl;
    }
 
    return 0;
}