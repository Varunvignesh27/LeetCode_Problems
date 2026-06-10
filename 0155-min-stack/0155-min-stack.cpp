class MinStack {
public:

    stack<int> s;
    map<int,int> mp;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        mp[value]++;
    }
    
    void pop() {
        mp[s.top()]--;
        if(mp[s.top()] == 0)
            mp.erase(s.top());
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mp.begin()->first;
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