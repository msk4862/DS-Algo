class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int s = 1, e = num;
        
        while(s<=e) {
            long long int m = (e-s)/2 + s;
            long long int sq = m*m;
            if(sq == num) return 1;
            else if (sq < num) s = m+1;
            else e = m-1;
        }
        
        return 0;
        
    }
};