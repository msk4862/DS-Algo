#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    map<T, list<T> > l;

    public:
        void addEdge(T s, T d) {
            l[s].push_back(d);
            l[d].push_back(s);
        }
        
        void bfs(T src) {
            map<T, bool> visited;
            queue<T> q;

            q.push(src);
            visited[src] = true;
            while(!q.empty()) {
                T v = q.front();

                // remove currently visited vertex
                cout<<v<<", ";
                q.pop();

                // tranverse neighbours of current node and push into queue and mark visited
                for(auto nbr:l[v]) {
                    if(!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            } 
        }
};

int main() {
    Graph<int> g;

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);

    return 0;
}