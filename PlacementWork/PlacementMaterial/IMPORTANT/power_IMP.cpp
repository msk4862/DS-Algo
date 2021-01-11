class Solution {
public:
    // IMPORTANT EDGE CASE
    // range of int = -2^31 to 2^31 -1
    // abs(-2^31) will be out of range
    // so take long for n
    
    double myPow(double x, long n) {
        if(n == 0) return 1;

        if(n < 0) return 1.0/myPow(x, -n); 
            
        if(n%2 == 0) {
            return myPow(x*x, n/2);
        }
        return x*myPow(x*x, n/2);
    }
};
