bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

class Solution {
public:
    int countBits(int n) {
        int c =0;
        while(n > 0) {
            n&=(n-1);
            c++;
        }
        return c;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> res;
        vector<int> ans(arr.size());

        for(int i = 0; i < arr.size(); ++i) {
            res.push_back({arr[i], countBits(arr[i])}); 
        }
        
        sort(res.begin(), res.end(), comp);
        for(int i = 0; i < arr.size(); ++i) {
            ans[i] = res[i].first; 
        }
      
        
        return ans;
    }
};