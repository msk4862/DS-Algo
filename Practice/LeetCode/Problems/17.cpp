class Solution {
public:
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", ""};
    
    void findCombs(string digits, vector<string> &combs, int i = 0, string cur="") {

        if(cur.size() == digits.size() || i > digits.size()) {
            combs.push_back(cur);
            cur = "";
            return;
        }

        int curDigit = digits[i]-'0';
        for(int ch = 0; ch < mp[curDigit].size(); ++ch) {
            cur += mp[curDigit][ch];
            findCombs(digits, combs, i+1, cur);
            cur.erase(cur.size()-1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        
        vector<string> combs;
        findCombs(digits, combs);
        return combs;
    }
};
