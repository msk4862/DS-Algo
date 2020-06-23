class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        
        return x*myPow(x, n-1);
    }
};


// O(logN)
class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(n < 0)
            return 1.0/myPow(x, -n);
        
        // a^6 = (a*a)^3
        else if(n%2 == 0)
            return myPow(x*x, n/2);

        // (a)^7 = a*(a)^6
        else return x*myPow(x*x, n/2);
    }
};