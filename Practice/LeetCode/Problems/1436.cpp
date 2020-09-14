class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> c;
        
        for(auto path:paths) {
            c[path[0]] = 1;
        }
        for(auto path:paths) {
            if(!c[path[1]])
                return path[1];
        }
        
        return "";
    }
};