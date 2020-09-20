class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> l;      
        
        int count=1;
        // counting all consecutives 
        for(int i=1; i<s.length(); ++i) {
            if(s[i]!=s[i-1]) {
                l.push_back(count);
                count=1;
            }
            else {
                count++;
            }            
        }
        
        l.push_back(count);
        
        int ans=0;
        for(int i=0; i<l.size()-1; ++i) {
            cout<<l[i]<<" ";
            ans+=min(l[i], l[i+1]);
        }
        
        return ans;
        
    }
};
