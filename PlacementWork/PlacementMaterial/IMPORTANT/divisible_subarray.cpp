class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int count = 0;
        
        int prefixSum = 0;
        unordered_map<int, int> sums;
        sums[0] = 1;
        // (a-b)%K = 0 => a%N = b%K
        for(int i = 0; i < A.size(); ++i) {
            prefixSum+=A[i];
            
            // to avoid negative value
            int diff  = ((prefixSum%K) + K)%K;
            // cout<<prefixSum%K)<<" ";
            if(sums[diff]) {
                count += sums[diff];
                sums[diff]+=1;
            }
            else sums[diff] = 1;
        }
        
        return count;
    }
};
