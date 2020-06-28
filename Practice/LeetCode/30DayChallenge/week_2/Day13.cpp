/*
    Contiguous Array
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> sums;
        
        int sum = 0;
        int maxLength = 0;
        
        // changing 0 to -1
        for(int i = 0; i < n; ++i) {
            if(nums[i]==0) nums[i] = -1;
        }
        
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if(sum==0) {if(maxLength < i+1) maxLength=i+1;} 
    
            else if(sums.count(sum)>0) {
                int start = sums[sum];
                int length = i-start;
                if(maxLength < length) maxLength=length;
            } 
            else sums[sum] = i;
        }
        
        return maxLength;
        
    }
};