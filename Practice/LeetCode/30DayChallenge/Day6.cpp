class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        
        unordered_map<string, vector<string>> mapping;
        for(int i = 0; i<strs.size(); ++i) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            mapping[cur].push_back(strs[i]);
        }
        
    
        for(pair<string, vector<string>> e : mapping) {
            groups.push_back(e.second);
        }
        
        return groups;
    }
};