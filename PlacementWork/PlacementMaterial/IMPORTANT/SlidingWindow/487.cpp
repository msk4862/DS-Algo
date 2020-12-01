// https://massivealgorithms.blogspot.com/2017/01/leetcode-487-max-consecutive-ones-ii.html

int findMaxConsecutiveOnes2(vector<int>& nums) {
        int longest = 0;
        int startWind = 0, endWind = 0;
        int zeroes = 0;

        for( ; endWind < nums.size(); endWind++) {
            if (nums[endWind] == 0) {
                zeroes++;
            }

            // zeroes inside the window > 1
            //shrink window to remove earlier zero inside window
            if (zeroes > 1) {
                while(nums[startWind++] != 0);
                zeroes = 0;
            }
            longest = max(longest, endWind - startWind +1);
        }
        
        
        return longest;
}