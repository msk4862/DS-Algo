class Solution {
public:
    // use temp array
    // time: O(n), space: O(d)
    void rotate1(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> temp;
        for(int i = n-k; i < n; ++i) {
            temp.push_back(nums[i]);
        }
        
        // shit rest by k 
        for(int i = n-k-1; i >= 0; --i) {
            nums[i+k] = nums[i];
        }
        
        // put temp array at start
        for(int i = 0; i < k; ++i) {
            nums[i] = temp[i];
        }
    }
    
    // shift one by one
    // time: O(k*n), space: O(1)
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = 0; i < k; ++i) {
            int temp = nums[n-1];
            
            for(int j = n-1; j >= 1; --j) {
                nums[j] = nums[j-1];
            }
            
            nums[0] = temp;
        }
    }
    
    
    void reverse(vector<int>& n, int st, int end) {
        for(int i = st, j = end; i < j; ++i, --j) {
            swap(n[i], n[j]);
        }
    }
        
    // time: O(n), space: O(1)
    void rotate3(vector<int>& nums, int k) {
        int n = nums.size();
        
        // reverse individual parts
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return;
        
        k %= n;
        // rotate1(nums, k);
        // rotate2(nums, k);
        
        rotate3(nums, k);
    }
};
