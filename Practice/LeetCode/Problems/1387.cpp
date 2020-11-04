unordered_map<int, int> dp;

class Solution {
public:
    
    int calcPower(int n) {
        if(n==1) return 0;
        
        // cout<<n<<" ";
        if(dp[n]) return dp[n];
        
        // odd
        if(n%2 == 1) {
            return dp[n] = calcPower(3*n+1)+1;
        }
        else {
            return dp[n] = calcPower(n/2)+1;
        }
        
    }
    
    static bool comp(pair<int, int> p1, pair<int, int> p2) {
        if(p1.second == p2.second) 
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> p;
        
        for(int i = lo; i <= hi; ++i){
            // cout<<i<<":"<<calcPower(i);
           p.push_back({i, calcPower(i)});
        }

        sort(p.begin(), p.end(), comp);
        
        cout<<p.size();
        return p[k-1].first;
    }
};
