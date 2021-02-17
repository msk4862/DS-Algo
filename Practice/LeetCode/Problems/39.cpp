class Solution {
public:
    // same as subset sum problem
    void combSumHelper(vector<int>& ar, int ind, int tar, vector<vector<int>>& res, vector<int> cur = {}) {
        if(ind == ar.size()) {
            if(tar == 0)  res.push_back(cur);
            return;
        }
        
        if(tar >= ar[ind]) {
            // include
            cur.push_back(ar[ind]);
            combSumHelper(ar, ind, tar-ar[ind], res, cur);            
            
            // exclude (backtrack)
            cur.pop_back();
            combSumHelper(ar, ind+1, tar, res, cur);
        }
        // can't inlcude only
        else {
            // exclude
            combSumHelper(ar, ind+1, tar, res, cur);
        }
    }
    
    void combSumHelper2(vector<int> ar, int start, int tar, vector<vector<int>>& res, vector<int> cur = {}) {
        if(tar == 0) { 
            res.push_back(cur);
            return;
        }

        for (int i = start; i < ar.size(); i++) {
            if(ar[i] <= tar) {
                cur.push_back(ar[i]);
                combSumHelper2(ar, i, tar-ar[i], res, cur);
                cur.pop_back();   
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        combSumHelper2(candidates, 0, target, res);
        
        return res;
    }
};
