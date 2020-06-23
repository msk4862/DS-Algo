class Solution {
public:
    unordered_map<int, int> a;
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        
        if(a.count(n)>0) return a[n];
        
        a[n] = climbStairs(n-1) + climbStairs(n-2);
        return a[n];
    }
};