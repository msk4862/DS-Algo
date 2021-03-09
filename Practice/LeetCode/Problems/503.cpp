class Solution {
public:
    // Time: O(2n), Space: O(2n)
    vector<int> nextGreaterElements1(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> maxCands;
        vector<int> res(n);
        
        vector<int> circular(nums.begin(), nums.end());
        for(int i = 0; i < n-1; ++i) circular.push_back(nums[i]);
        
        // circular part
        for(int i = circular.size()-1; i >= n; --i) {
            while(!maxCands.empty() &&  maxCands.top() <= circular[i]) {
                maxCands.pop();
            }
            maxCands.push(circular[i]);
        }
        
        for(int i = n-1; i>=0; --i) {
            while(!maxCands.empty() &&  maxCands.top() <= nums[i]) {
                maxCands.pop();
            }
            res[i] =  maxCands.empty() ? -1 : maxCands.top();
            
            maxCands.push(nums[i]);
        }
        
        return res;
    }    
    
    // Time: O(2n), Space: O(1) (apart from output array)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> maxCands;
        vector<int> res(n);
        
        // circular part
        for(int i = n-2; i >= 0; --i) {
            while(!maxCands.empty() &&  maxCands.top() <= nums[i]) {
                maxCands.pop();
            }
            maxCands.push(nums[i]);
        }
        
        for(int i = n-1; i>=0; --i) {
            while(!maxCands.empty() &&  maxCands.top() <= nums[i]) {
                maxCands.pop();
            }
            res[i] =  maxCands.empty() ? -1 : maxCands.top();
            
            maxCands.push(nums[i]);
        }
        
        return res;
    }
};
