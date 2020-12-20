class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res; 
        
        // either sort sums and use two pinter -> O(n^2logn)
        // or use hash map with extra auxilary space -> O(n^2) - duplicates
        
        sort(nums.begin(), nums.end());
            
        for(int i = 0; i < nums.size(); ++i) {
            // skip dups
            if(i > 0 && nums[i-1] == nums[i]) continue;
            
            for(int j = i+1; j < nums.size(); ++j) {
            
                // skip dups
                if(j > i+1 && nums[j-1] == nums[j]) continue;

                //a+b+c+d = target
                // a, b are fixed
                int first = nums[i] + nums[j];
                int sec = target - first; 
                
                // 2sum
                int l = j+1, h = nums.size()-1;
                while(l < h) {
                    
                    if(l > j+1 && nums[l-1] == nums[l]) {
                        l++;
                        continue;
                    };
                    if(h < nums.size()-1 && nums[h+1] == nums[h]) {
                        h--;
                        continue;
                    }
                    
                    if(nums[l] + nums[h] == sec) {
                        res.push_back({nums[i], nums[j], nums[l], nums[h]});
                        l++;
                        h--;
                    }
                    else if(nums[l] + nums[h] < sec) l++;
                    else h--;
                }
            }
            
        }
            
        return res;
        
    }
};
