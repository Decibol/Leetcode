class MinStack {
private:
    stack<int> st;
    stack<int> minimum;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minimum.empty() || val <= minimum.top()){
            minimum.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        if (!st.empty() && st.top() == minimum.top()){
            minimum.pop();
        }
        
        st.pop();
    }
    
    int top() {
        return st.empty() ? INT_MIN : st.top();
    }
    
    int getMin() {
        return minimum.empty() ? INT_MIN : minimum.top(); 
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