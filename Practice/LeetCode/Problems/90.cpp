class Solution {
public:
    

    void subset(vector<int> a, vector<vector<int>>& res, int ind=0, vector<int> cur = {}) {
        res.push_back(cur);
        for (int i = ind; i < a.size(); i += 1) {
            
            // checking for dups when cur is not empty
            if(i!=ind and a[i] == a[i-1]) continue;
            cur.push_back(a[i]);
            subset(a, res, i+1, cur);
            cur.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        // to make duplicates together
        sort(nums.begin(), nums.end());
        subset(nums, res);
        
        return res;
    }
};