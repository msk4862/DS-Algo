class Solution {
public:
    bool isOneBitCharacter(vector<int>& b) {
        int n = b.size();
        if(n==1) return 1;
        if(b[n-1]==1) return 0;
        if(n==2 && b[0]==0 && b[0]==b[1]) return 1;
        if(n==2) return 0;
        
        int last;
        for(int i=0; i<n;++i) {
            if(i==n-1) return 1;
            if(b[i]==1) i++;
            else continue;   
        }
        
        return 0;
    }
};
