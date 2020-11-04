class Solution {
public:
    static bool comp(vector<int> p1, vector<int> p2) {
        // if(p1[0] == p2[0])
        //     return p1[1] > p2[1];
        return p1[1] < p2[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {

        if(points.size() == 0) return 0;
        
        sort(points.begin(), points.end(), comp);
        
        int bows = 1;
        
        int prevY = points[0][1];
        
        // hit bow at where ballon ends
        for(int i=1; i < points.size(); ++i) {
            if(prevY < points[i][0]) {
                bows++;
                prevY = points[i][1];
            }
        }
        
        return bows;
    }
};
