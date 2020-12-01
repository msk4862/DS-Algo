class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // sliding window solution works only if nums[i] > 0
        
        /*
        int n = nums.size();
        
        // using sliding window
        int startWindow = 0, endWindow = 0;
        int curSum = nums[startWindow];
        
        int res = 0;
        while(endWindow < n) {
            if(curSum == k) {
                res++;
                endWindow++;
                continue;
            }
            // expand
            if(curSum < k) {
                if(endWindow < n) curSum += nums[endWindow];
                endWindow++;
            }
            // shrink
            else {
                curSum -= nums[startWindow];
                startWindow++;
            }
        }
        
        return res;
        */
        
        // hash map solution
        long sum = 0;
        int l = nums.size();
        
        unordered_map<int, int> sumFreq;
        int count=0;
        
        sumFreq[sum] = 1;
        for(int i = 0; i < l; ++i) {
            sum += nums[i];
            
            // sum-i = k, i = sum-k (i's are cumulative sums stored in map)
            // so we have to find if i  already exist
            if(sumFreq.find(sum-k) != sumFreq.end()) {
                count+=sumFreq[sum-k];
            }
            sumFreq[sum]+=1;
        }
        
        // for(auto x:sumFreq) cout<<x.first<<" ";
        
        return count;
    }
};