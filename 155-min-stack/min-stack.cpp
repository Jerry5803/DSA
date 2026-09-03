class MinStack {
public:
    stack<int> myStack;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int value) {
        myStack.push(value);

        if (minStack.empty()) {
            minStack.push(value);
        }

        else {
            value = min(value, minStack.top());
            minStack.push(value);
        }
    }
    
    void pop() {
        myStack.pop();
        minStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */