/*
  Subarray Sum Equals K
  Using Brian Kernighan’s Algorithm

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long sum = 0;
        int l = nums.size();
        
        unordered_map<int, int> sumFreq;
        int count=0;
        
        sumFreq[sum] = 1;
        for(int i = 0; i < l; ++i) {
            sum += nums[i];
            
            // sum-i = k, i = sum-k (i's are cumulative sums stored in map)
            // so we have to find if i  already exist
            if(sumFreq.count(sum-k) > 0) {
                count+=sumFreq[sum-k];
            }
            
            if(sumFreq.count(sum)> 0)
                sumFreq[sum]+=1;
            else
                sumFreq[sum]=1;
            
            
        }
        
        // for(auto x:sumFreq) cout<<x.first<<" ";
        
        return count;
    }
};