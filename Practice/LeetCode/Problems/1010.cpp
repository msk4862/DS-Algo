class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int N = 60;
        int count = 0;
        
        unordered_map<int, int> mp;
        
        // if (a + b)%N = 0 then (a%N + b%N)%N = 0 also
        // c = a%N, d = b%N
        // c+d = N
        for(int t : time) {
            int c = (N - t%N)%N;
            
            if(mp.find(c) != mp.end()) {
                count += mp[c];
                
            }
            
            // if not already added
            if(mp[t%N] == 0)
                mp[t%N] = 1;

            // already present value
            else 
                mp[t%N] +=1;
        }
        
        return count;
    }
};
