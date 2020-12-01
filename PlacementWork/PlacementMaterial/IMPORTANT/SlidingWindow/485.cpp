class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longest = 0;
        
        int cur = 0;
        for(int e : nums) {
            if(e)
                cur++;
            else
                cur = 0;
        
            longest = max(longest, cur);
        }
        
        return longest;
    }
};