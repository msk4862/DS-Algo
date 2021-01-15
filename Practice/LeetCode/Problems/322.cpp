class Solution {
public:
    int minCoins_td(vector<int>& c, int amt, int dp[]) {
        if(amt == 0) return 0;
    
        if(dp[amt] != -2) return dp[amt];

        // not needed if it ensured that ans will lie in int range
        // then we can just check if minCoinsRequired is still INT_MAX after the loop
        // as done in bottom up approach
        bool changePossible = false;
        int minCoinsRequired  = INT_MAX;
        for(int i = 0; i < c.size(); ++i) {
            int coins = -1;
            if(c[i] <= amt) coins = minCoins_td(c, amt-c[i], dp);

            if(coins != -1) changePossible = true;
            minCoinsRequired = min(minCoinsRequired, coins==-1? INT_MAX : coins);
        }

        return dp[amt] = changePossible ? minCoinsRequired + 1 : -1;
    }
    
    int minCoins_bu(vector<int>& coins, int amt) {
        int dp[amt+1];
        dp[0] = 0;
        
        for(int i = 1; i <= amt; ++i) {
            int minCoinsRequired  = INT_MAX;

            for(int c = 0; c < coins.size(); ++c) {
                int ways = -1;
                if(coins[c] <= i) ways = dp[i - coins[c]];

                minCoinsRequired = min(minCoinsRequired, ways==-1? INT_MAX : ways);
            }
            
            dp[i] = minCoinsRequired==INT_MAX ? -1 : minCoinsRequired+1;
        }
        
        return dp[amt];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0) return -1;
        
        // int dp[10001];
        // for(int i = 0; i <= amount; ++i) dp[i] = -2;
        // return minCoins_td(coins, amount, dp);
        
        return minCoins_bu(coins, amount);
        
    }
};
