class Solution {
public:
    static bool comp(int a, int b) {
        return a> b;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        if(n<=1) return n; 
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            mp[position[i]] = speed[i];
        }
        sort(position.begin(), position.end(), comp);
        
        int fleets = 0;
        
        float t1 = 0;
        for(int i = 0; i < n; ++i) {
            float t2 = float(target-position[i])/mp[position[i]];
            if(t1 < t2) {
                fleets++;
                t1 = t2;
            }
        }
        
        return fleets;
    }
};
