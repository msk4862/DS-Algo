class Solution {
public:
    
    void subset(int start, int n, int k, vector<vector<int>>& res, vector<int> cur={}) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        
        for(int i = start; i <= n; ++i) {
            cur.push_back(i);
            subset(i+1, n,k,res,cur);
            cur.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        
        subset(1, n, k, res);
        return res;
    }
};