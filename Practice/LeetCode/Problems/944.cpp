class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int cols = A[0].length();
        
        int ans=0;
        
        for(int j = 0; j < cols; ++j) {
            for(int i = 0; i < A.size()-1 && A[i][j] > A[i+1][j]; ++i) {
                if() {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};