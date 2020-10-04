class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int l=ops.size();
        int xmin=m, ymin=n;
        for(int i=0; i<l; ++i) {
            xmin= min(xmin, ops[i][0]);
            ymin= min(ymin, ops[i][1]);
        }
        
        return xmin*ymin;
    }
};