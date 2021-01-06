class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return;
        
        // permuations of elements after peek element are done 
        //now need to change next element in lex order in place of current peek
        int peek;
        for(peek = n-2; peek >= 0; --peek) {
            if(nums[peek] < nums[peek+1]) break; 
        }
        
        cout<<peek;
        
        // if peak is found
        // if its not that means its last permutaion
        if(peek  >= 0) {
            // seraching next element next element in lex order, in place of current peek
            for(int i = n-1; i > peek; i--) {
                if(nums[peek] < nums[i]) {
                    swap(nums[peek], nums[i]); 
                    break;
                }
            }
        }
        sort(nums.begin()+peek+1, nums.end());
        
    }
};
