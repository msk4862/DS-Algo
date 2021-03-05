class Solution {
public:
    // O(n)
    int sqrt1(int x) {
        if(x<2) return x;
        
        int i;
        for(i = 1; i <= x/2; ++i) {            
            long sq = (long)i*i;
            if(sq == x) return i;
            else if(sq > x) return i-1; 
        }
        
        return i-1;
    }
    
    // O(logn)
    int sqrt2(int x) {
        int l = 1, h = x;
        while(l <= h) {
            int mid = (h - l)/2 + l;
            long sq = (long)mid*mid;
            
            if(sq == x) return mid;
            else if(sq < x) l = mid+1;
            else h = mid-1;
        }
        
        return h;
    }
    
    int mySqrt(int x) {
        // return sqrt1(x);
        return sqrt2(x);
        
    }
};
