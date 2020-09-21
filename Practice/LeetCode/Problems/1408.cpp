class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        int l = words.size();
        string sub[l];
        vector<string> res;
                
        string t = "";
        for(int i=1; i<l; ++i) {
            t+=words[i-1] + " ";
            sub[i] = t;
        }
        
        
        t = "";
        for(int i=l-2; i>=0; --i) {
            t+=words[i+1] + " ";
            sub[i] += t;
        }
        for(int i=0; i<l; ++i) {
            if(sub[i].find(words[i]) != string::npos) {
                res.push_back(words[i]);
            }
        }
        
        
        return res;
        
    }
};
