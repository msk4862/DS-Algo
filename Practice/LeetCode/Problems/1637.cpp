class Solution {
public:
    static bool comp(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }
    
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        
        int maxW = INT_MIN;
        for(int i = 0; i < points.size()-1; ++i) {
            maxW = max(maxW, points[i+1][0] - points[i][0]);
        }
        
        return maxW;
    }
};