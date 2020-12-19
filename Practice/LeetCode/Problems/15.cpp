class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 3sum = 2sum + nums[i]
        vector<vector<int>> res;
        
        if(nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
        
        int prev;
        for(int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            
            // skip dups
            if(i> 0 && prev == nums[i]) continue;
            prev = nums[i];
            
            int target = 0 - nums[i];
            
            int l = i+1, h = nums.size()-1;
        
            int prevl, prevH;    
            // 2sum
            while(l < h) {
                
                // skip dups
                if(l > i+1 && nums[l-1]==nums[l]) {
                    l++;
                    continue;
                }
                
                if(h < nums.size()-1 && nums[h+1]==nums[h]) {
                    h--;
                    continue;
                }
                
                if(nums[l] + nums[h]  == target) {
                    cout<<nums[l]<<" "<<nums[h];
                    res.push_back({nums[i], nums[l], nums[h]});
                    l++;
                    h--;
                    
                }
                else if(nums[l] + nums[h]  < target) l++;
                else h--;
            }
        }
        
        return res;
    }
};
