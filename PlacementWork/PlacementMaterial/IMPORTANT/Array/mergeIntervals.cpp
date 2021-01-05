class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        // to make mergable intervals consecutive
        //thsts why sort
        // contradictory example for explainig why not sort accrding to end  
        // (1,4), (3,5), (6,9), (0,10)
        sort(intervals.begin(), intervals.end(), comp);
        
        int s = intervals[0][0];
        int e = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); ++i) {
            // interval overlap
            if(e >= intervals[i][0]) {   
                // expand current interval if its less than next interval's end's
                e = max(e, intervals[i][1]);
            }
            else {
                res.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        
        res.push_back({s, e});        
        
        return res;
    }
};
