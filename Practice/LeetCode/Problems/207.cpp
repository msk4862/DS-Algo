
class Graph {
    int V;
    vector<vector<int>> adjList;
    
    public:
    
        Graph(int v) {
            V = v;
            adjList = vector<vector<int>>(v); 
        }    
        void addEdge(int s, int d) {
            adjList[s].push_back(d);
        }
        
        bool isCycleHelper(int src, vector<bool> &visited,vector<bool> &in_stack) {    
            visited[src] = in_stack[src] = true;
            for(int adj: adjList[src]) {
                if(in_stack[adj]) return true;
                if(!visited[adj]) 
                    if(isCycleHelper(adj, visited, in_stack)) return true;      
            }
            
            // visited all adjacent nodes of src recusively
            // and no cycle found
            // removing src from stack
            in_stack[src] = false;
            return false;
        }
        
        bool isCycle() {            
            vector<bool> visited(V, false);
            // if its in current path
            // for cases like 1->2<-3
            vector<bool> in_stack(V, false);
            
            for(int i = 0; i < V; ++i) {
                if(!visited[i]) {
                    // for each connected component 
                    if(isCycleHelper(i, visited, in_stack)) return true; 
                }
            }
            return false;
        }
    
};

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        
        for(int i = 0; i < prerequisites.size(); ++i) {
            g.addEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        
        return !g.isCycle();
    }
};
