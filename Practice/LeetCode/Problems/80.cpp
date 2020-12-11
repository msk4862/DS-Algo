class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        for(int start = 0, end = 2; end < nums.size(); ++start, ++end) {
            if(nums[start] == nums[end]) {
                cout<<end;
                nums.erase(nums.begin() + end);
                
                // don't move forward
                // check for more duplicate
                start-=1;
                end -=1;
            }
        }
    
        return nums.size();
    }
};
