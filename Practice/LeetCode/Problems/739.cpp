class Solution {
public:
    
    // same as next greater
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> wait(n);

        if(n ==1) {
            wait[0]=0;
            return wait;
        }
        
        stack<int> nums;
        nums.push(0);
          
        for(int i = 1; i < n; ++i) {
            int next = i;
            while(!nums.empty() and T[nums.top()] < T[next]) {
                wait[nums.top()] = next-nums.top();
                nums.pop();
            }
            
            nums.push(next);
        }
        
        while(nums.empty()) {
            wait[nums.top()] = 0;
            nums.pop();
        }
        
        return wait;
    }
};