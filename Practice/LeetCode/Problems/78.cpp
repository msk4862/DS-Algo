class Solution {
public:
    void subset(vector<int> a, vector<vector<int>>& res, int ind=0, vector<int> cur = {}) {
        res.push_back(cur);
        for (int i = ind; i < a.size(); i += 1) {
            cur.push_back(a[i]);
            subset(a, res, i+1, cur);
            cur.pop_back();
        }
        return;

    }


    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        subset(nums, res);
        
        return res;
    }
};
