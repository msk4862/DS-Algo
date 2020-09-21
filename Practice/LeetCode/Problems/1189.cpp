class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string b = "balloon";
        unordered_map<char, int> m;        
        
        for(auto ch:text) m[ch]++;
        
        int ans = INT_MAX;
        for(auto ch:b) {
            if(ch == 'l' or ch=='o')
                ans = min(m[ch]/2, ans);
            else 
                ans = min(m[ch], ans);
        }
        
        return ans;
        
    }
};
