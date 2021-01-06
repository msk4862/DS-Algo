class Solution {
public:
    
    // time: O(n*n)
    // Space: O(n*n)
    vector<int> getRow1(int row) {
        vector<int> pre = {1};
        
        for(int i = 2; i <= row+1; ++i) {
            vector<int> cur(i, 1);
            // first and last values are 1
            for(int j = 1; j < i-1; ++j) {
                cur[j] = pre[j-1] + pre[j];
            }
            
            pre = cur;
        }
        
        return pre;
    }
    
    // nCr = n-1Cr + n-1Cr-1
    int C(int n, int r) {
        if(n < r) return 0;
        if(n == r) return 1;
        
        if(r == 0) return 1;
        
        return C(n-1, r) + C(n-1, r-1);
    }
    
    
    // time: O(n)
    // Space: O(n)
    vector<int> getRow2(int row) {
        vector<int> res(row+1, 1);
        
        if(row < 2) return res; 
        
        res[1] = C(row, 1);
        
        // caculating nCr+1 from nCr
        // to optimise
        for(int i = 2; i <= row; ++i) {
            res[i] = (res[i-1]*(long)(row-(i-1)))/i;
        }
        
        return res;
    }
    
    vector<int> getRow(int rowIndex) {
        // brute force
        // return getRow1(rowIndex); 
    
        // optimised
        // using formula : C(r-1, c-1) - pascal value for rth row and cth col
        return getRow2(rowIndex); 
        
    }
};
