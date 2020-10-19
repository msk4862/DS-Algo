class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        unordered_map<int, int> brackets;
        for(int i=0; i<s.size(); ++i) {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')') {
                int last = st.top();
                st.pop();
                
                brackets[i] = last;
                brackets[last] = i;
            }
        }
        
        for(auto e: brackets) cout<<e.first<<" "<<e.second;
        
        int rev = 1;
        string res="";
        for(int i=0; i < s.size() && i >= 0; i+=rev) {
            // change direction
            if(s[i] == '(' or s[i] == ')') {
                rev*=-1;
                // move to other pair of the bracket
                i = brackets[i];
                s[i] = '-';
            }
            else if(s[i] != '-'){
                res += s[i];
            }
        }
        
        return res;
    }
};