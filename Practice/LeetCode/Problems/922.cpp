class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size()), odd, even;
        
        
        for(int i = 0; i < A.size(); ++i) {
            if(A[i]%2 ==0) even.push_back(A[i]);
            else odd.push_back(A[i]);
        }
        
        int k = 0;
        for(int i = 0; i < A.size(); i+=2) {
            res[i] = even[k++];
        }
        
        k = 0;
        for(int i = 1; i < A.size(); i+=2) {
            res[i] = (odd[k++]);
        }
        return res;
        
    }
};