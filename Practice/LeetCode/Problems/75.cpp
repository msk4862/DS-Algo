class Solution {
public:
    void sortColors(vector<int>& nums) {
        //1st approach- sort(nums.begin(), nums.end());  

        //2nd approach- constant space but two passes
        int ct[3] = {0};
        for(int n:nums) {
            ct[n]++;
        }
        
        int st = 0;
        // zero
        for(int i = 0; ct[0]!=0; ++i) {
            if(nums[i] == 0) {
                int t = nums[st];
                nums[st] = nums[i];
                nums[i] = t;
                st++;
                ct[0]--;
            }
        }
        
        // one
        for(int i = st; ct[1]!=0; ++i) {
            if(nums[i] == 1) {
                int t = nums[st];
                nums[st] = nums[i];
                nums[i] = t;
                st++;
                ct[1]--;
            }
        }
        
        
        // 3rd approach - one pass
        
        int i=j=0;
        for(int k = 0; k < nums.size(); ++i) {
            int cur = nums[k];
            nums[k]=2;
            
            if(cur < 2) {
                nums[j] = 1;
                j++;
            }
            if(cur == 0) {
                nums[i] = 0;
                i++;
            }
        }
    }

    /* one pass elaborated algo 

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int zero = -1, one= -1, two=-1;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 2) {
                nums[++two] = 2;
            }
            
            else if(nums[i] == 1) {
                two++;
                
                if(one+1 < n && nums[one + 1] == 2) {
                    nums[two] = 2;
                }
                nums[++one] = 1;
            }
            
            else {
                one++;
                two++;
                // there are elemnts after 0's
                if(zero + 1 < n && nums[zero + 1] == 1) {
                    nums[one] = 1;
                    // there are 2's also
                    if(one < two) nums[two] = 2;
                }
                // there are only 2's after 0's
                else if(zero + 1 < n && nums[zero+1] == 2) {
                    nums[two] = 2;
                }
                
                nums[++zero] = 0;
            }
        }
    }
    */
};
