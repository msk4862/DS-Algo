/*
      Product of Array Except Self
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productTillNow = 1;
        
        int n = nums.size();
        vector<int> products(n);
        
        for(int i= 0; i< n; ++i) {
            products[i] = productTillNow;
            productTillNow *= nums[i]; 
        }
        
        productTillNow = 1;
        
        for(int i= n-1; i>=0; --i) {
            products[i] *= productTillNow;
            productTillNow *= nums[i]; 
        }
        
        return products;
        
    }
};