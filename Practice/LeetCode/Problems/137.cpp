class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // counting set bits
        int count[32] = {0};
        for (int i = 0; i < nums.size(); i += 1) {
            for (int ind = 0; ind < 32; ind += 1) {
                if(nums[i]&(1<<ind))
                    count[ind]++;
            }
        }

        int res = 0;
        // now every element will 3n value in count except single element bits
        for (int i = 0; i < 32; i += 1) {
            count[i]%=3;

            if(count[i])
            res |= 1<<i;
        }   
        
        return res;
    }
};
