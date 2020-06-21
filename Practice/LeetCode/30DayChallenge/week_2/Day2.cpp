/*
  Backspace String Compare
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // stack<int> s1, s2; -> will use O(N) space 
        
        for(int i = 0; i < S.length();++i) {
            if (S[i] == '#') 
                if(i-1 >= 0) {
                    S.erase(i-1, 2);
                    i-=2;
                }
                else {
                    S.erase(i, 1);
                    i-=1;
                }
        }
        
        for(int i = 0; i < T.length();++i) {
            if (T[i] == '#') 
                if(i-1 >= 0) {
                    T.erase(i-1, 2);
                    i-=2;
                }
                else {
                    T.erase(i, 1);
                    i=-1;
                }
        }
        // cout<<S<<" "<<T;
        
        return S == T;
    } 
};