class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> initialFactors;
        vector<int> endFactors;
        
        for(int i = 1; i <= sqrt(n); ++i) {
            if(n%i == 0) {
                initialFactors.push_back(i);
                if(float(n/i) != i) endFactors.insert(endFactors.begin(), n/i);
            }
        }
        
        
        if(initialFactors.size() >= k) return initialFactors[k-1];
        k -= initialFactors.size();
        if(endFactors.size() >= k) return endFactors[k-1];
        
        
        return -1;
        
        
        // O(sqrt(n)), space O(1)
        // first half
        for(int i = 1; i <= sqrt(n); ++i) {
            if(n%i == 0) {
                if(k==1) return i;
                k--;
            }
        }
        
        // second half of factors
        for(int i = (int)sqrt(n); i >= 1; --i) {
            if(n%i == 0) {
                if(k==1) return n/i;
                k--;
            }
        }
        return -1;
        
    }
};
