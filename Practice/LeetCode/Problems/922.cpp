class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size()), odd, even;
        
        
        for(int i = 0; i < A.size(); ++i) {
            if(A[i]%2 ==0) even.push_back(A[i]);
            else odd.push_back(A[i]);
        }
        
        int o = 0, e=0;
        for(int i = 0; i < A.size(); i++) {
            if(i%2)
                res[i] = odd[o++];
            else
                res[i] = even[e++];
        }
        
        return res;
        
    }
};