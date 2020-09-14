class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> a;
        
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_map<char, string> m;
        
        char t = 'a'; 
        for(int i = 0; i < 26; ++i, ++t) {
            m[t] = code[i];
        }
        
        for(string w : words) {
            string tra = "";
            for(char c : w) {
                tra+=m[c];
            } 
            
            a.insert(tra);
        }
        
        // for(auto e: a) cout<<e<<" ";
        
        return a.size();
    }
};