class Solution {
public:
    
    // Divide and Conquer - O(N^2)
    int getScore(string S, int s, int e) {
        // S = ()
        if(s+1==e) return 1;
        
        // build stack
        stack<char> st;
        st.push(S[s]);
        
        int i = s+1; 
        while(!st.empty()) {
            if(S[i] == '(') st.push(S[i]);
            else st.pop();
            i++;
        }

        // case 1: (A)
        if(i-1 == e) return 2*getScore(S, s+1, e-1);
        // case 2: AB
        return getScore(S, s, i-1) + getScore(S, i, e);
    }
    
    int scoreOfParentheses(string S) {
        
        //return getScore(S, 0, S.size()-1);
    /*    
        // Time: O(N), space = O(N)
        stack<int> s;
        int score = 0;
        for(char e: S) {
            // more depth
            if(e == '(') {
                s.push(score);
                score = 0;
            }
            else {
                // depth score- (AB) + AB score
                score = max(2*score, 1) + s.top();
                s.pop();
            }
        }
        
        return score;*/
        
        
        int score = 0;
        // Space: O(1)
        int layer = 0;
        for(int i = 0; i < S.size(); ++i) {
            if(S[i] == '(') layer++;
            else layer--;
            // ()
            if(S[i] == ')' && S[i-1] == '(') score += 1<<layer;
        }

        return score;
    }
    
};