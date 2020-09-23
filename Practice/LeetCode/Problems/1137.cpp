class Solution {
public:
    int tribonacci(int n) {
        int f=0,s=1,t=1;
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        
        int nth;
        for(int i=3; i<=n;++i) {
            nth = f+s+t;
            f=s;
            s=t;
            t=nth;
        }
        
        return nth;
    }
};