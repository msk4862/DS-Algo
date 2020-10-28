class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int s3 = INT_MIN;
        
        for(int i = nums.size()-1; i >= 0; --i) {
            // new s1 found
            if(nums[i] < s3) return true;
            
            // s2, s3 cadidates found
            while(!st.empty() && st.top() < nums[i]) {
                s3 = st.top();
                st.pop();
            }
            
            st.push(nums[i]);   
        }
        
        return false;
    }
};
