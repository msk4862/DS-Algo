class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        
        stack<char> st;
        
        // remove peeks
        for(int i = 0; i < num.size(); ++i) {
            while(k > 0 && !st.empty() && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        // if k !=0 then last elems must be removed
        res = res.substr(0, res.size()-k);
        
        //remove trailling 0
        int j = 0;
        while(res[j] == '0') {
            res.erase(0, 1);
        }

            
        if(res.size() == 0) res = "0";
        
        return res;
    }
};
