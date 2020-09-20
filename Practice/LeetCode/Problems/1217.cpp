class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int o=0, e=0;
        
        for(int i = 0; i < pos.size(); ++i) {
            if(pos[i]%2) o++;
            else e++;
        }
        return min(o, e);
    }
};
