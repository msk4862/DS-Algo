class MinStack {
public:
    /** initialize your data structure here. */
    vector<pair<int, int>> s;
    
    MinStack() {
    } 
    
    void push(int x) {
        if (s.size() == 0) 
            s.push_back(make_pair(x, x));  
        else {
            int minSoFar = s.back().second;
            if(minSoFar > x) s.push_back(make_pair(x, x));
            else s.push_back(make_pair(x, minSoFar));
        }
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */