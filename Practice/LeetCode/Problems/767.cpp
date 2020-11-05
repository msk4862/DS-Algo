class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        string res = string(n, ' ');
            
        vector<int> ct(26, 0);
        int maxFreq = 0, maxL;
        for(char c: S) {
            int ind = int(c -'a');
            ct[ind]++;
            
            if(maxFreq < ct[ind]) {
                maxFreq = ct[ind];
                maxL = ind;
            }
        }
        
        // in first pass we are filling - (0, 2, 4, ...)  (0 is also included)  
        // if below true then it will repeat in second pass
        if(maxFreq > (n+1)/2) return "";
        
        
        // fill alternate chars
        // will be done in two passes
        int i = 0;
        while(ct[maxL] > 0) {
            res[i] = char('a'+maxL);
            ct[maxL]--;                
            i+=2;
        }
              
        for(int  ch = 0; ch < 26; ++ch) {
            while(ct[ch] > 0) {
                if(i >= n) i=1;
 
                res[i] = char('a'+ch);
                ct[ch]--;
                
                i+=2;
            }    
        }
        
        return res;
    }
};
