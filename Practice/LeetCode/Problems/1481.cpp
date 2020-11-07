class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> ct;
        
        for(auto e:arr) {
            ct[e]++;
        }

        vector<int> c;
        for(auto e:ct) {
            c.push_back(e.second);
        }
        
        sort(c.begin(), c.end());
        
        int ans = c.size();
        int  i =0;
        while(k > 0) {
            if(c[i] <= k) {                
                k-=c[i];
                ans--;
            }
            else k=0;
            i++;
        }
        
        return ans;
    }
};
