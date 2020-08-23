class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        
        bool trusts[N+1];
        int trusted_by[N+1];
        
        memset(trusts, 0, sizeof(trusts));
        memset(trusted_by, 0, sizeof(trusted_by));
        
        for(int i = 0; i < trust.size(); ++i) {
            trusts[trust[i][0]] = 1;
            trusted_by[trust[i][1]]++;
        }
        
        for(int i = 1; i <= N; ++i) {

            if(trusted_by[i] == N-1) {
                    if(!trusts[i]) {
                        return i;
                    }
                    else {
                        return -1;
                    }
            }
        }
        return -1;
    }
};