class MyStack {
public:
    queue < int > q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int x = q.size()-1;
        int ans = q.back();
        while(x--)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
        return ans;
    }
    
    int top() {
        int x = q.back();
        return x;
    }
    
    bool empty() {
        if(q.empty())
            return true;
        else
            return false;
    }
};
