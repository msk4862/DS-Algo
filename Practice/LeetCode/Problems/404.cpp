class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int q = queries.size();
        int sum = 0;
        for(auto e:A) if(e%2==0) sum+=e;
        
        vector<int> res;
        
        for(int i=0; i <q;++i) {
            int val = queries[i][0];
            int ind = queries[i][1];
            
            //if in the sum
            if(A[ind]%2==0)
                sum-=A[ind];
            
            A[ind] += val;
            if(A[ind]%2==0)
                sum+=A[ind];
            
            res.push_back(sum);
        }
        
        return res;
    }
};
