class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
         
        // if wanted was unique solution set then sort and two pointer approach will be used
        // here we can just use hash map approach because dups are allowed
        
        // sum, count
        unordered_map<int, int> mp; 
        
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A.size(); ++j) {
                // cout<<A[i]<<B[j];
                mp[A[i] + B[j]]++;  
            }
        }
        
        int res = 0;
        
        //A[i] + B[j] = - (C[k] + D[l])
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A.size(); ++j) {
                int sum = -(C[i] + D[j]);
                if(mp[sum])
                   res += mp[sum];
            }
        }
        return res;
    }
};
