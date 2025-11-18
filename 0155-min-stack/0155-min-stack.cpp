class MinStack {
private:
    stack<int> st;
    stack<int> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        if (st.top() == minStack.top()){
            minStack.pop();
        }

        if (!st.empty()) st.pop();
    }
    
    int top() {
        return st.empty() ? INT_MIN : st.top();
    }
    
    int getMin() {
        return minStack.empty() ? INT_MIN : minStack.top();
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