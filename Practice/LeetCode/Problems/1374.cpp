class Solution {
public:
    string generateTheString(int n) {
        char t = 'a';
        
        string res = "";
        if(n%2==0) {
            for(int i = 0; i < n-1; ++i) {
                res+=t;
            }   
            res+=(t+1);
        }
        else {
            for(int i = 0; i < n; ++i) {
                res+=t;
            }
        }
        
        return res;
    }
};