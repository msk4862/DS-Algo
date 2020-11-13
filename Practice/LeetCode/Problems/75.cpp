class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());  
        // constant space but two passes
        int ct[3] = {0};
        for(int n:nums) {
            ct[n]++;
        }
        
        int st = 0;
        // zero
        for(int i = 0; ct[0]!=0; ++i) {
            if(nums[i] == 0) {
                int t = nums[st];
                nums[st] = nums[i];
                nums[i] = t;
                st++;
                ct[0]--;
            }
        }
        
        // one
        for(int i = st; ct[1]!=0; ++i) {
            if(nums[i] == 1) {
                int t = nums[st];
                nums[st] = nums[i];
                nums[i] = t;
                st++;
                ct[1]--;
            }
        }
        
        
        // one pass
        
        int i=j=0;
        for(int k = 0; k < nums.size(); ++i) {
            int cur = nums[k];
            nums[k]=2;
            
            if(cur < 2) {
                nums[j] = 1;
                j++;
            }
            if(cur == 0) {
                nums[i] = 0;
                i++;
            }
        }
    }
};
