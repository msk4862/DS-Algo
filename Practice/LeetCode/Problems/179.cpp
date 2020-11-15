class Solution {
public:
    static bool comp(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        
        // not required
        // if(sa.size() == sb.size()) return sa > sb;
        // concat
        return sa + sb > sb + sa ;
    }
    
    string largestNumber(vector<int>& nums) {
        string res = "";
        
        sort(nums.begin(), nums.end(), comp);   
        // all zeroes
        if(nums[0] == 0) return "0";
        
        for(int num : nums) {
            // cout<<num<<" ";
            res += to_string(num);
        }
        
        return res;
    }
};
