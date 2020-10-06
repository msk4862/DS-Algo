class Solution {
public:
    
    void subset_sum(vector<int> a, int tar, vector<vector<int>>& res, int start = 0, vector<int> cur = {}, int sum = 0) {
        
        if(sum == tar) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i < a.size(); i ++) {
            if(sum + a[i] <= tar) {
                cur.push_back(a[i]);
                sum+=a[i];
                subset_sum(a, tar, res, i, cur, sum);
                sum -= cur[cur.size()-1];
                cur.pop_back();   
            }
        }
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> res;
        
        subset_sum(can, target, res);
        return res;
    }
};