class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> s;
        for(auto e: stones) s.push(e);
        
        while(s.size()>1) {
            int s1 = s.top();
            s.pop();
            int s2 = s.top();
            s.pop();
            
            if(s1 != s2) s.push(abs(s1-s2)); 
        }
        
        if(s.size()==1) return s.top();
        else return 0;
    }
};