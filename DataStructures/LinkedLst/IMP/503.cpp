class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return vector<int>();
        if(n==1) return vector<int>(1, -1);
                
        // expand array
        for(int i =0; i < n; ++i) nums.push_back(nums[i]);
        
        vector<int> res(n);
        stack<int> num;
        
        int elem=0;
        num.push(0);
        for(int i = 1; i < 2*n; ++i) {
            int next = nums[i];
            
            while(!num.empty() && nums[num.top()] < next) {
                res[num.top()] = next;
                num.pop();
            }
            
            if(i < n)
            num.push(i);
        }
        
        while(!num.empty()) {
            res[num.top()] = -1;
            num.pop();
        }
        
        return res;
    }
};