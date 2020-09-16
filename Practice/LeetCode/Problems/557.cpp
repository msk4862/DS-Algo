class Solution {
public:
    string reverseWords(string s) {
        int l = s.length();
        
        if(l < 2) return s;
        
        for(int i = 0; i < l; ++i) {
            int j = i+1;
            while(j < l && s[j] != ' ') j++;
            reverse(s.begin()+i, s.begin()+j);
            i = j;
        }        
        return s;
    }
};