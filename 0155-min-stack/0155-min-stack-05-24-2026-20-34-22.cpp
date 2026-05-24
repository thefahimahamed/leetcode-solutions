class MinStack {
private : stack < int > s;
private : vector < int > small;
private : unordered_map < int , int > m;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        m[val]++;
        if(small.empty())
        small.push_back(val);
        else if(val < small.back())
        small.push_back(val);
        else
        return;
    }
    
    void pop() 
    {
        int temp = s.top();
        s.pop();
        m[temp]--;
        if(temp == small.back() && m[temp] == 0)
        small.pop_back();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return small.back();
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