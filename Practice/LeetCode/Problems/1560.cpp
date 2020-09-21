class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        
        int s = rounds[0];
        int l = rounds[rounds.size()-1];
        if(s< l) {
            
            for(int i = l; i>=s; --i) {
                res.push_back(i);
            } 
            sort(res.begin(), res.end());
        }
        else if(s >l){
            for(int i = s; i<=n; ++i) {
                res.push_back(i);
            }
            
            for(int i = 1; i<=l; ++i) {
                res.push_back(i);
            }
            sort(res.begin(), res.end());

        }
        
        else  {
            res.push_back(s);
        }
        return res;
    }
};
