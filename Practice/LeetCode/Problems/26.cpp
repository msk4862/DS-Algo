class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int l = 0, h = 1;
        for(int h = 1; h < nums.size(); ++h) {
            if(nums[l] != nums[h])  nums[++l] = nums[h];
        }
        
        return l+1;
    }
};
