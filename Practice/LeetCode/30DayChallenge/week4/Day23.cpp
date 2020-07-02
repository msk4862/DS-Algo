/*
  Bitwise AND of Numbers Range

*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = n;
        int i = n-1;
        
        while(ans > m) {
            ans = ans&(ans-1);
            if(ans == 0) 
                return ans;
        }
        
        return ans;
    }
};