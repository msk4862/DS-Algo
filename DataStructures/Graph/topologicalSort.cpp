#include<bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, vector<int>> adjList;

    public:
        void addEdge(int s, int d) {
            adjList[s].push_back(d);
        }
        
        void dfs(int src, unordered_map<int, bool> &visited, list<int>& order) {
       
            visited[src] = true;

            for(int adj: adjList[src]) {
                if(!visited[adj]) {

                    dfs(adj, visited, order);        
                }
            }
            order.push_front(src);

        }

        list<int> topologicalSortDFS() {
      		// vertex, indegree
        	unordered_map<int, bool> visited;
        	list<int> order;

        	for(auto vert : adjList) {
        		int node = vert.first;
        		if(!visited[node])
        			dfs(node, visited, order);
        	}

        	return order;
        }   
};



int main() {
    Graph g;

    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(1, 3); 

    list<int> res = g.topologicalSortDFS();
    for(int el : res) {
    	cout<<el<<"->";
    }

    return 0;
}