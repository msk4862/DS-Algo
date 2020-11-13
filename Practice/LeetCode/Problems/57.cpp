class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {    
        int s = 0, e = 0, n = intervals.size();
        
        // starting merge point
        while(s < n && intervals[s][1] < newInterval[0]) {
            s++;
        }
        
        cout<<s<<n;
        e = s;
        
        if(e < n) {
            newInterval[0] = min(newInterval[0], intervals[e][0]);
            
        // ending merge point 
            while(e < n && intervals[e][1] <= newInterval[1]) {
                e++;
            }
            
            cout<<e;

            if(e < n && intervals[e][0] <= newInterval[1]) {
                newInterval[1] = intervals[e][1];
                e++;
            }
        }
        
        intervals.erase(intervals.begin() + s, intervals.begin() +e);
        intervals.insert(intervals.begin() + s, {newInterval[0], newInterval[1]});
        
        return intervals;
    }
};
