class Solution {
public:
    
    static bool sortF(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first; 
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int> res; 
        vector<pair<int, int>> sol;
        
//         using BINARY SERACH
        
//         for(int i = 0; i < rows; ++i) {
//             int s = 0, e = cols-1;
//             while(s <=e) {
//                 int m = (s+e)/2;
                
//                 if(mat[i][m] == 1) s=m+1;
//                 else e=m-1;
//             }
            
//             sol.push_back({s, i});
//             // cout<<s<<" ";
//         }
        
//         stable_sort(sol.begin(), sol.end(), sortF);
        
//         int j = 0;
//         for(int i = 0; i < k; ++i) {
//             // cout<<sol[i].first<<":"<<sol[i].second<<" ";
//             res.push_back(sol[j++].second);
//         }
        
//         other APPROACH
        unordered_map<int, bool> m;
        for(int i = 0; i < cols; ++i) {
            for(int j = 0; j < rows; ++j) {
                if(!m[j] and !mat[j][i]) {
                    m[j] = 1;
                    res.push_back(j);
                    k--;
                   if(!k) break; 
                }
            }
            if(!k) break;
        }
        
        for(int i = 0; k>0 && i < rows; ++i) {
            if(!m[i]) {
                res.push_back(i);
                k--;
            }
        }
        return res;
    }
};