class Solution {
public:
    int majorityElementHelper(vector<int> nums) {
        int majEl = nums[0], count = 1;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(majEl == nums[i]) count++;
            else if(count > 0) count--;
            else {
                majEl = nums[i];
                count = 1;
            }
        }
        
        return majEl;
    }
    
    int majorityElement(vector<int>& nums) {
        // 1st approach 
        // count all element's freq
        // O(n), O(n)
        
        // 2nd approach
        // sort element and return n/2 th element
        // O(nlogn), O(1)
        
        // 3rd approach
        // frequency of majority element
        // is greater than rest of the elemnts
        // O(n), O(1)
        return majorityElementHelper(nums);
    }
};
