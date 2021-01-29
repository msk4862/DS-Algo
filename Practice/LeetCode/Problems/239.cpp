class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {    
        deque<int> maxEl;
	
        int end;
        // process first window	
        // storing the values maintaining descending order 
        for (end = 0; end < k; end += 1) {
            // if new element is greater
            while(!maxEl.empty() && nums[maxEl.back()] < nums[end]) {
                maxEl.pop_back();
            }
            maxEl.push_back(end);
        }
        
        int n = nums.size();

        vector<int> res;
        for (int start = 1; start <= n-k+1; start += 1) {            
            res.push_back(nums[maxEl.front()]);

            // shrink from front 
            // window have been moved to right
            while(!maxEl.empty() && maxEl.front() < start) {
                maxEl.pop_front();
            }

            // extend from back
            // remove lower values from back if new value is greater	
            while(end<n && !maxEl.empty() && nums[maxEl.back()] <= nums[end]) {
                maxEl.pop_back();
            }
            
            maxEl.push_back(end);
            end++;	
        }

        return res;
    }
};
