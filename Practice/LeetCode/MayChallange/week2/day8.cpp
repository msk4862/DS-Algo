class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n==2) return 1;
    
        int mx = (coordinates[1][0] - coordinates[0][0]);
        if(mx==0) {
            for(int i = 2; i < n; ++i) {
                int mx1 = (coordinates[i][0] - coordinates[i-1][0]);
                if(mx1 != 0) return 0;
            }
            
            return 1;
        }
        else {
            double m = (double) (coordinates[1][1] - coordinates[0][1])/mx;
            
            cout<<m<<" ";
            for(int i = 2; i < n; ++i) {
                int mx1 = (coordinates[i][0] - coordinates[i-1][0]);

                if(mx1 == 0) return 0;
                
                double m1 = (double) (coordinates[i][1] - coordinates[i-1][1])/mx1;
                            cout<<m1<<" ";

                if(m!=m1) return 0;                
            }
        }
        
        return 1;
    }
};