class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // hash map appraoch - O(N) space
        // sorting approach - O(NlogN) time - will modify array
        
        // fast slow pointer approach
        // linked list cycle detection approach

        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
