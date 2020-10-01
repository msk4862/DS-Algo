class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int s=0,l=n.size()-1;
        vector<int> res;
        while(s <= l) {
            if(n[s]+n[l] == target) {
                res.push_back(s+1);
                res.push_back(l+1);
                return res;
            }
        
            else if(n[s]+n[l] < target) s++;
            else l--;
        }
    return res;

    }
};