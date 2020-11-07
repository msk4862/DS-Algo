class Solution {
public:
    static bool comp(vector<int> p1, vector<int> p2 ) {
        if(p1[0] == p2[0]) {
            // of high y value
            return p1[1] > p2[1];
        }
        return p1[0] < p2[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int x1 = intervals[0][0];
        int y1 = intervals[0][1];
        
        int cov = 0;

        int i = 1;
        while(i < intervals.size()) {

            int x2 = intervals[i][0];
            int y2 = intervals[i][1];
            
            if(x1 <= x2 && y1>=y2) {
                cov++;
            }
            else {
                x1 = x2;
                y1 = y2;
            }
            i++;
        }
        
        return intervals.size()-cov;
    }
};
