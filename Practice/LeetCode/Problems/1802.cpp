class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // merge two sorted array
        vector<int> res(nums.size());
        int k = nums.size()-1;
        
        for(int start = 0, end = nums.size()-1; start<=end;) {
            if(abs(nums[start]) < abs(nums[end])) {
                res[k--] = pow(nums[end], 2);
                end--;
            }
            else {
                res[k--] = pow(nums[start], 2);
                start++;
            }
        }
        
        return res;
    }
};
