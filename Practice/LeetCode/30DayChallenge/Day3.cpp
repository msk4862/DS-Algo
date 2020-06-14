#include<bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = INT_MIN, currentSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            currentSum = currentSum+nums[i];
            if(largest < currentSum) {
                largest = currentSum;
            }
            if(currentSum < 0) {
                currentSum = 0;
            }
            
            
        }
        
        return largest;
    }
};