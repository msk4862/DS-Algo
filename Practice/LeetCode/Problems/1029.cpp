class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort by abs(costA - costB)
        // because for persons having large diff b/w citeis
        // we have to send him to the nearest one to reduce cost
        
        /*
        sort(costs.begin(), costs.end(), [](vector<int> p1, vector<int> p2) {
            return abs(p1[0]-p1[1]) > abs(p2[0]-p2[1]);
        });
        
        int a = 0, b = 0, minCost = 0;
        int half = costs.size()/2;
        for (int i = 0; i < costs.size(); i++) {
            if(a == half || b == half) {
                if(a == half) {
                    minCost += costs[i][1];
                }
                else minCost += costs[i][0];
            }
            else {
                if(costs[i][0] <= costs[i][1]) {
                    a++;
                    minCost += costs[i][0];
                }
                else {
                    b++;
                    minCost += costs[i][1];
                }
            }
        }
        
        return minCost;
        */
        
        // cleaner code
        // Da = distance from city A
        // as Da - Db is increasing It means Da increasing or Pb is decreasing
        // So, We can take initial vales from Da and later values of Db 
        sort(costs.begin(), costs.end(), [](vector<int> p1, vector<int> p2) {
            return (p1[0]-p1[1]) < (p2[0]-p2[1]);
        });
        
        int minCost = 0;
        int half = costs.size()/2;
        for (int i = 0; i < costs.size()/2; i++) {
            minCost += costs[i][0];
        }
        
        for (int i = costs.size()/2; i < costs.size(); i++) {
            minCost += costs[i][1];
        }
        
        return minCost;
    
    }
};
