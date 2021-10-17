// Implement a queue using two stacks
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

//lass queue
class Queue{
    stack<int> s1, s2;
 
public:
    // add an item to the queue
    void enqueue(int data)
    {
        // move all elements from the first stack to the second stack
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
 
        // push item into the first stack
        s1.push(data);
 
        // move all elements back to the first stack from the second stack
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
 
    //delete an item from the queue
    int dequeue()
    {
        // if the first stack is empty
        if (s1.empty())
        {
            cout << "stack Underflow";
            exit(0);
        }
 
        // return the top item from the first stack
        int top = s1.top();
        s1.pop();
        return top;
    }
};
 
int main()
{
    int keys[] = { 13, 6, 7, 9, 10 };
    Queue q;
 
    // insert above keys
    for (int key: keys) {
        q.enqueue(key);
    }
    cout << q.dequeue() << endl;    // print 1
    cout << q.dequeue() << endl;    // print 2
 
    return 0;
}