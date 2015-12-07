/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.

*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        int top;
        if (que[0].empty()) {
            que[0].push(x);
            while (!que[1].empty()) {
                top = que[1].front();
                que[0].push(top);
                que[1].pop();
            }
        }
        else if (que[1].empty()) {
            que[1].push(x);
            while (!que[0].empty()) {
                top = que[0].front();
                que[1].push(top);
                que[0].pop();
            }
        }        
    }

    // Removes the element on top of the stack.
    void pop() {
        if (que[0].empty()) {
            que[1].pop();
        }
        else if (que[1].empty()) {
            que[0].pop();
        }
    }

    // Get the top element.
    int top() {
          if (que[0].empty()) {
            return que[1].front();
        }
        else if (que[1].empty()) {
            return que[0].front();
        }      
    }

    // Return whether the stack is empty.
    bool empty() {
        return (que[0].empty() && que[1].empty());
    }
private:
    queue<int> que[2];
};