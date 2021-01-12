class Solution {
public:
    int merge(vector<int>& n, int l, int m, int h) {
        int n1 = m-l+1;
        int n2 = h - m;
        
        int L[n1], R[n2];
        for(int i = 0; i < n1; ++i) L[i] = n[l+i];
        for(int i = 0; i < n2; ++i) R[i] = n[m+i+1];
        
        int pairs = 0;
        int rightInd = 0;
        for(int leftInd = 0; leftInd < n1; ++leftInd) {
            // find reverse pairs
            while(rightInd < n2 && L[leftInd] > long(2)*R[rightInd]) {
                rightInd++;
            }  
            pairs += rightInd;
        }
            
        // merge L and R
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) n[k++] = L[i++];
            else n[k++] = R[j++];
        }
        while(i < n1) {
            n[k++] = L[i++];
        }
        
        while(j < n2) {
            n[k++] = R[j++];
        }
        
        return pairs;
    }    
    
    
    // same as counting inversions
    int mergeSort(vector<int>& n, int l, int h) {
        if(l < h) {
            int m = (h-l)/2 + l;
            int leftPairs = mergeSort(n, l, m);
            int rightPairs = mergeSort(n, m+1, h);
            return merge(n, l, m, h) + leftPairs + rightPairs;
        }
        return  0;
    }
    
    int reversePairs(vector<int>& nums) {
        int r = mergeSort(nums, 0, nums.size()-1);
        for(int e:nums)cout<<e<<" ";

        return r;
    }
};
