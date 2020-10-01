class Solution {
public:
    string longestWord(vector<string>& w) {
        int n = w.size();
        
        sort(w.begin(), w.end());
        
        unordered_set<string> s;
        
        string res="";
        for(int i=0; i<n;++i) {
            if(w[i].length() ==1 or s.find(w[i].substr(0, w[i].length()-1))!=s.end()) {
                s.insert(w[i]);
                
                res = w[i].length() > res.length()? w[i]:res;

            }
            
        }   
        
        return res;
    }
};
