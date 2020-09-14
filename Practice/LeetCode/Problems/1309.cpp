class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '1' || s[i] == '2') {
                if(i+2 < s.length() && s[i+2] == '#') {
                    res+= ('a' + stoi(s.substr(i, 2))-1);
                    i+=2;
                }
                else {
                    res += ('a' + (int(s[i])-'0'-1));
                }
            }
            else {
                    res += ('a' + (int(s[i])-'0'-1));
            }
        }
        
        
        return res;
    }
};