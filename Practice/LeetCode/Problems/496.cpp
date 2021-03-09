class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> maxCands;
        unordered_map<int, int> mp;
        
        for(int i = nums2.size()-1; i >= 0; --i) {
            while(!maxCands.empty() && maxCands.top() <= nums2[i]) {
                maxCands.pop();
            }
            mp[nums2[i]] = maxCands.empty() ? -1 : maxCands.top();   
            
            // can be a possible max candidate
            maxCands.push(nums2[i]);
        }
        
        vector<int> res;
        for(int num:nums1) {
            res.push_back(mp[num]);
        }
        
        return res;
    }
};
