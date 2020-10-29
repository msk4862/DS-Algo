class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string act = "";
        long size = 0;
        
        int N;
        for(N =0; N < S.size() && K >= size; ++N) {            
            if('a'<= S[N] && S[N]<= 'z') {
                size++;
                act += S[N];
            }                
            else size *= (S[N]-'0');
        }
        for(int i =N-1; i >= 0; --i) {            
            K %= size;

            if(K ==0 && S[i] >= 'a' && S[i] <='z') return (string) "" + S[i];
            
            if(S[i] >= 'a' && S[i] <='z') size--;
            else {
                size /= (S[i]-'0');
            }
        }
        return "";
    }
};
