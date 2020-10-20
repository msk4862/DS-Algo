class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> m;


        int j = 0;
        for(int i = 0; i < pushed.size(); ++i) {
            m.push(pushed[i]);
            
            while(!m.empty() && popped[j] == m.top()) {
                m.pop();
                j++;
            }
        }
            
        
        
        return m.size()==0;
    }
};