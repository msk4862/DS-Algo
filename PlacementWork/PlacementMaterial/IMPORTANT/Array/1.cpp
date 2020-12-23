class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // wa can use two pointer tecnique too with O(nlogn)
        // but it more useful to find all those unique pair
        // currently we can use hash map approach 
        
        // val, index
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); ++i) {
            int b = target - nums[i];
            if(mp.find(b) != mp.end()) 
                return vector<int>{mp[b], i};
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
