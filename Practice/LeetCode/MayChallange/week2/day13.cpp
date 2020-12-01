class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(int i = 0; i < num.size(); ++i) {
            while(k > 0 && !st.empty() && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        string res = "";
        int place = 1;
        while(!st.empty()) {
            res = st.top() + res;  
            st.pop();
        }
        
        while(res[0] == '0') {
            res = res.substr(1);
        }
        
        if(res.size() == 0) res = "0";
        
        return res;
    }
};