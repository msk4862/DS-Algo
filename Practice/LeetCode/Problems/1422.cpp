class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int z = 0;

        int maxS = INT_MIN;
        for(int i=0; i<s.length()-1; ++i) {
            if(s[i]=='0') {
                z++;
            }
            else {
                ones--;
            }
                        
            maxS = max(z+ones, maxS);   
        }
        
        return maxS;
    }
};
