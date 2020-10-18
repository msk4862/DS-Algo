class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        
        
        for(auto e:s) {
            if(e == '(' or e == '{' or e == '[') 
                p.push(e);
            else if(p.empty()) return false;
            else if(p.top() == '(' && e != ')') return false;
            else if(p.top() == '{' && e != '}') return false;
            else if(p.top() == '[' && e != ']') return false;
            else p.pop();
        }
        
        if(p.empty()) return true;
        return false;
    }
};