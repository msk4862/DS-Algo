class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> a;
        string res="";
        // a.push(S[0]);
//         for(int i = 1; i < S.size(); ++i) {
//             if(!a.empty() && a.top() == S[i]) {
//                 a.pop();
//             }
//             else {
//                 a.push(S[i]);
//             }
//         }
        
//         while(!a.empty()) {
//             res = a.top() + res;
//             a.pop();
//         }
        int j = 0;
        for(int i = 0; i < S.size(); ++i) {
            S[j] = S[i];
            
            if(j > 0 && S[j] == S[j-1]) j--;
            else j++;
        }
        return S.substr(0, j);
    }
};