class Solution {
public:
    // same as next permutation problem
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int s = num.size();
        
        int peek;
        for(peek = s-2; peek >=0; --peek) {
            if(num[peek] < num[peek+1]) break;
        }
        
        // cout<<peek<<" ";
        // number is already largest
        if(peek == -1) return -1;
        
        // finding next greator element
        for(int i = s-1; i >= peek-1; --i) {
            if(num[peek] < num[i]) {
                swap(num[peek], num[i]);
                break;
            }
        }
    
        sort(num.begin()+peek+1, num.end());

        long greater = stol(num);
        return greater > INT_MAX ? -1 : greater;
    }
};
