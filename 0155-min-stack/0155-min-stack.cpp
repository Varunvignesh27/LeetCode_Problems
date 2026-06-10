class MinStack {
public:

    stack<int> s;
    vector<int> pm;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(!pm.empty())
            pm.push_back(min(*(pm.rbegin()),value));
        else
            pm.push_back(value);
    }
    
    void pop() {
        s.pop();
        pm.pop_back();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *(pm.rbegin());
    }
};