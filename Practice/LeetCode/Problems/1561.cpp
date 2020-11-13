class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        int n = piles.size();
        
        int maxC = 0;
        int least = 0;
        for(int i =n-2; i > least; i-=2) {
            maxC+=piles[i];
            least++;
        }
        
        return maxC;
    }
};