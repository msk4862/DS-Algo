class Solution {
public:
    bool isPerfectSquareHelper1(int num) {
        double root = sqrt(num);
        return root-(int)root == 0 ? true:false;
    }
    
    bool isPerfectSquareHelper2(int num) {
        int l = 1, h = num;
        while(l <= h) {
            int mid = (h-l)/2 +l;
            long sq = (long)mid*mid;
            if(sq == num) return true;
            else if(sq < num) l = mid+1;
            else h = mid-1;
        }
        
        return false;
    }
    
    bool isPerfectSquare(int num) {
        return isPerfectSquareHelper2(num);
    }
};
