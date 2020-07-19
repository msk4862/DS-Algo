//   Arranging Coins


class Solution {
public:
    
    // O(n)    
    int arrangeCoins(int n) {

        int pre = 0;
        int count = 0;
                
        while(n > pre) {
            pre+=1;
            n-=pre;
            count++;
        }
        
        return count;
    }
        
        //O(lg(n))
    
        long getSum(int k) {
            return (k)*(k+1)/2;
        }
        int arrangeCoins(int n) {

            long l = 0, e = n;
            long m;
            while(l <= e) {
                m = (e-l)/2 +l;
                long k = getSum(m);

                if(k <= n)
                    l=m+1;
                else 
                    e=m-1;
            }

            return (int)l-1;
        }
    }
    
    // O(1)
    int arrangeCoins(int n) {
    // using linear eqality (k(k+1)/2 <= N)
        
        return floor(sqrt((long)2*n + 0.25)-0.5);
        
    }

};