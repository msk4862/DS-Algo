class Solution {
public:
    
    void subset(vector<int> a, vector<vector<int>>& res, vector<bool> used, vector<int> cur={}) {
        if(cur.size() == a.size()) {
            res.push_back(cur);
            return;
        }
        
        for(int i = 0; i < a.size(); ++i) {
            if(used[i]) continue;
            cur.push_back(a[i]);
            used[i] = true;
            subset(a, res, used, cur);
            cur.pop_back();
            used[i] = false;
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        
        subset(nums, res, used);
        
        return res;
    }  
};