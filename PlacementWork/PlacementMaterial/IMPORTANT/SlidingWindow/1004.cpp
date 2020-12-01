// https://massivealgorithms.blogspot.com/2019/03/leetcode-1004-max-consecutive-ones-iii.html


int findMaxConsecutiveOnes3(vector<int>& nums, int k) {
        int longest = 0;
        int startWind = 0, endWind = 0;
        int zeroes = 0;

        for( ; endWind < nums.size(); endWind++) {
            if (nums[endWind] == 0) {
                zeroes++;
            }

            // zeroes inside the window > 1
            //shrink window to remove earlier zero inside window
            while (zeroes > k) {
                if(nums[startWind++] == 0) zeroes--;
            }
            
            longest = max(longest, endWind - startWind +1);
        }
        
        
        return longest;
}