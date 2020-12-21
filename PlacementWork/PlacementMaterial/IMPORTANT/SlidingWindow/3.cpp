class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // char, index+1
        unordered_map<char, int> mp;
        int res = 0;
        int l = 0, h = 0;
        
        while(h < s.size()) {
            
            // repeating char found
            // which is inside window
            if(mp[s[h]] && mp[s[h]]-1 >= l) {            
                // move starting point
                
                // remove elem which are outside window
                // while(l < mp[s[h]]) {
                //     mp.erase(s[l]);
                //     l++;
                // }
                
                l = mp[s[h]];
            }
            else {
                // storing last occurence of a char
                mp[s[h]] = h+1;
                res = max(res, h-l+1);
                h++;
            }
        }
        
        return res;
    }
};
