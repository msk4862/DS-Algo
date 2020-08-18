
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char, pair<int, bool>> m;
        
        
        for(int i = 0; i < n; ++i) {
            if(m.find(s[i]) != m.end()) {
                m[s[i]] = {i, 0};
            }
            else {
                m[s[i]] = {i, 1};
            }
        }
        
        int ind = n;
        for(auto e: m) {
            if(e.second.second) {
                ind= min(ind, e.second.first);
            }       
        }
        
        if(ind == n) return -1;
        return ind;
    }
};