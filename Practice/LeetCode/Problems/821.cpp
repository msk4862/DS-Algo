class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        
        vector<int> res(S.length());
        int pre = -10000;
        for(int i = 0; i < S.length(); ++i) {
            if(S[i] == C) {
                res[i] = 0;
                pre = i;
            }
            else {
                res[i] = i-pre;
            }
        }
        
        pre = 10000;
        for(int i = S.length()-1; i >= 0 ; --i) {
            if(S[i] == C) {
                pre = i;
            }
            else {
                res[i] = min(res[i], pre-i);
            }
        }
        
        return res;
    }
};
