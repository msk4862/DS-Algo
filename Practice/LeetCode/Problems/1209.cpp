class Solution {
public:
    string removeDuplicates(string s, int k) {
        // char, count
        stack<pair<char, int>> st;
        
        st.push({s[0], 1});
        for(int i = 1; i < s.size(); ++i) {
            // increase count if same
            if(!st.empty() && st.top().first == s[i]) {
                auto t = st.top();
                t.second++;
                st.pop();
                st.push(t);
            }
            else {
                st.push({s[i], 1}); 
            }
            if(st.top().second == k) {
                st.pop();
            }
        }
        string res = "";
        
        while(!st.empty()) {
            auto e = st.top();
            while(e.second > 0) {
                res = e.first + res;
                e.second--;
            }
            st.pop();
        }
        
        return res;
    }
};