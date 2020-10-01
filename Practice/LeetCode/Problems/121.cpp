class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // kaden's algo
        if(prices.size()==0) return 0;
        
        int minS = INT_MAX, maxP = INT_MIN;
        for(int i=0; i<prices.size(); ++i) {
            minS = min(minS, prices[i]);
            maxP = max(maxP, prices[i]-minS);
        }
        
        return maxP;
    }
};