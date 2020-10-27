class Solution {
public:
    // https://www.youtube.com/watch?v=9-TXIVEXX2w
    
    void findNle(vector<int> a, vector<int> &n) {
        stack<int> nle;
        
        for(int i = 0; i < a.size(); ++i) {
            while(!nle.empty() && a[nle.top()] > a[i]) {
                n[nle.top()] = i;
                nle.pop();
            }
            nle.push(i);
        }
        
        while(!nle.empty()) {
            n[nle.top()]  =-1;
            nle.pop();
        }
    }
    
    void findPle(vector<int> a, vector<int> &p) {
        stack<int> ple;
        
        for(int i = a.size()-1; i >= 0; --i) {
            // equal to for duplicates small (2,3,4,1,5,6)
            while(!ple.empty() && a[ple.top()] >= a[i]) {
                p[ple.top()] = i;
                ple.pop();
            }
            ple.push(i);
        }
        
        
        while(!ple.empty()) {
            p[ple.top()]  =-1;
            ple.pop();
        }
    }
    
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        int MOD = 1000000007;
        
        // previuos less elem
        vector<int> ple(n);
        // next ''
        vector<int> nle(n);
        
        findNle(A, nle);
        findPle(A, ple);
        
        // k1 greater elems, n, k2 greater elem 
        // subarr with n as minimum = (k1 +1)*(k2+1)
    
        int sum = 0;
        
        for(int i = 0; i < n; ++i) {
            // max values
            int pre_greater = i;
            int next_greater = n-i-1;
        
            if(ple[i] != -1) pre_greater = i-ple[i]-1;
            if(nle[i] != -1) next_greater = nle[i]-i-1;
            
            // cout<<prevs<<" "<<nexts<<":";
            // cout<<ple[i]<<" "<<nle[i]<<":";
            
            int cur_contri = (A[i] * ((pre_greater+1)%MOD * (next_greater+1)%MOD)%MOD)%MOD;
            
            sum = (sum + cur_contri)%MOD;
        }
        
        return sum;
    }
};
