class Solution {
    static const int mod = 1000000007;
public:
    static long power(long x, long n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        
        // even
        if((n&1) ==0)
            return power((x*x)%mod, n/2);
        else
            return (x*power((x*x)%mod, n/2))%mod;
    
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        
        sort(nums.begin(), nums.end());
        long res = 0;
        while(l<=h) {
            if(nums[l] + nums[h] <= target) {
                res= (res+ power(2, h-l)%mod)%mod;
                l++;
            }
            else h--;
        }
        
        return res;
        
    }
};
