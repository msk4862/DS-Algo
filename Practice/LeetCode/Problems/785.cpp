class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int src, vector<int> &color, bool preColor = 1) {
        
        color[src] = preColor ? 1 : 2;
        for(int adj : graph[src]) {
            if(!color[adj]) {
                if(!dfs(graph, adj, color, !preColor)) return false;
            }
            else if(color[adj] == color[src]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        
        for(int i = 0; i < n; ++i)
            if(!color[i])
                if(!dfs(graph, i, color)) return false;
        
        return true;
    }
};
