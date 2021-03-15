class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            // if number is in range then
            // 1. we will swap it in correct range
            // 2. Where we are swapping it(A[A[i]-1]), its already present there
            // it will couse infinite loop 
            // Hence check of A[A[i] - 1] != A[i]
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
                swap(A[i], A[A[i]-1]);
            }
        }

        for(int i = 0; i < n; ++i) {
            if(A[i] != i+1) return i+1;
        }

        return n+1;
    }
};
