class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        // O(nlogn)
        /*
        sort(citations.begin(), citations.end(), [](int a, int b) {
            return a > b; 
        });
        
        int h = 0;
        while(h < citations.size() && h+1 <= citations[h] ) {
            h++;
        }
        
        return h;
        */
        
        // Time: O(n), Space: O(n) 
        // using count sort
        int n = citations.size();
        vector<int> count(n+1, 0);
        
        for(int c : citations) {
            if(c >= n) count[n]++;
            else count[c]++;
        }
        
        // int larger = 0;
        
        for(int i = n; i > 0; --i) {
            if(count[i] >= i)   return i;
            else count[i-1]+=count[i];
        }
        
        return 0;
        
    }
};
