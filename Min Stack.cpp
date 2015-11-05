/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if (min_stk.empty())
            min_stk.push(x);
        else {
            if (x <= min_stk.top()) {
                min_stk.push(x);
            }
        }    
    }

    void pop() {
        int top = stk.top();
        stk.pop();
        if (top == min_stk.top())
            min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
private:
    stack<int> stk;
    stack<int> min_stk;
};