class StockSpanner {
public:
    // num, less num count
    stack<pair<int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        if(s.empty()) s.push({price, 1});
        else {
            int count = 1;
            // pop all less and add count
            while(!s.empty() && s.top().first <= price) {
                count += s.top().second;
                s.pop();
            }
            s.push({price, count});
        }
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
class StockSpanner {
public:
    // num, less num count
    stack<pair<int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        if(s.empty()) s.push({price, 1});
        else {
            int count = 1;
            // pop all less and add count
            while(!s.empty() && s.top().first <= price) {
                count += s.top().second;
                s.pop();
            }
            s.push({price, count});
        }
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */