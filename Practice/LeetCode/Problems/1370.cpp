class Solution {
public:
    string sortString(string s) {
        string res= "";
        
        int c[26] = {0};
        for(int i = 0; i < s.length(); ++i) {
            c[s[i]-'a']++;
        }

        int rev = 0;
        while(res.length() != s.length()) {
            string t ="";
            for(int i = 0;  i < 26;++i )  {
                if(c[i]) {
                    t+=char(i+97);
                    c[i]--;
                }
            }
            rev++;
            if(rev%2==0) reverse(t.begin(), t.end());
                
            res += t;
        }
        
        
        return res;
    }
};