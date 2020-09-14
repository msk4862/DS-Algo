class Solution {
public:
    vector<int> sumZero(int n) {
        int t = -(n/2);
        
        bool f = 1;
        if(n%2 == 0) f=0; 
        
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            if(!f and t == 0) {
                t++;
            }
            res.push_back(t);
            t++;
        }
        
        return res;
    }
};