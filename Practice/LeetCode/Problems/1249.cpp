class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        
        for(int  i =0; i<  s.size(); ++i) {
            if(s[i] == '(') {
                st.push({'(', i});
            }
            else if(s[i] == ')') {
                if(st.empty() or st.top().first != '(') st.push({')', i});
                else st.pop();
            }
        }
        
        if(st.empty()) return s;

        while(!st.empty()) {
            s.erase(st.top().second, 1);
            st.pop();
        }
        
        return s;
    }
};