class Solution {
public:
    // https://leetcode.com/problems/majority-element-ii/discuss/63537/My-understanding-of-Boyer-Moore-Majority-Vote
    
    vector<int> majorityElementH(vector<int> nums) {
        int maj1 = -1, maj2 = -1;
        int count1 = 0, count2 = 0;
        
        for(int el : nums) {
            if(maj1 == el) count1++;
            else if(maj2 == el) count2++;
            else if(count1 == 0) {
                maj1 = el;
                count1 = 1;
            }
            else if(count2 == 0) {
                maj2 = el;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0; count2 = 0;
        // confirming using count
        for(int el : nums) {
            if(el == maj1) count1++;
            else if(el == maj2) count2++;
        }
        
        vector<int> res;
        if(count1 > nums.size()/3) res.push_back(maj1);
        if(count2 > nums.size()/3) res.push_back(maj2);
        
        return res;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        // 1st approach
        // hashmap soln
        
        // 2nd approach
        // we know at max we will have 2 majority element
        
        return majorityElementH(nums);
    }
};
