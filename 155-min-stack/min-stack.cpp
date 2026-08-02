class MinStack {
public:
    stack<int> mainSTK;
    stack<int> minSTK;
    MinStack() {
        
    }
    
    void push(int value) {
        mainSTK.push(value);
        if(!minSTK.empty()){
            minSTK.push(min(minSTK.top(), value));
        }
        else{
            minSTK.push(value);
        }
    }
    
    void pop() {
        mainSTK.pop();
        if(!minSTK.empty()){
            minSTK.pop();
        }

    }
    
    int top() {
        return mainSTK.top();
        
    }
    
    int getMin() {
        return minSTK.top();
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