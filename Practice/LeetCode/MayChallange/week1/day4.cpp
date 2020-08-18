class Solution {
public:
    
    int findComplement(int num) {
        int ans=0, n = 1;
        while(num > 0) {
            if((num&1) == 0) 
                ans |= n;

            n<<=1;
            num>>=1;            
        }
        
        return ans;
    }
};