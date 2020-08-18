class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> m;
        
        for(int i = 0; i < J.length(); ++i) {
            m[J[i]] = 0;
        }
        
        int t = 0;
        for(int i = 0; i < S.length(); ++i) {
            if(m.find(S[i])!=m.end())
                t++;
        }
        return t;
    }
};