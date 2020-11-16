class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        //O(nlogn)
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         for(int i = 0; i < s.size(); ++i) {
//             if(s[i] != t[i]) return false; 
//         }
        
//         return true;
        
        // O(n)
        unordered_map<char, int> sc;
        for(char e : s) {
            sc[e]++;
        }
        for(char e : t) {
            if(sc[e] > 0) sc[e]--;
            else return false;
        }
        
        for(auto e: sc) if(e.second > 0) return false;
        
        return true;
    }
};
