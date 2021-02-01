#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);
typedef pair<int, int> pi; 

class Graph {
    int n;
    vector<pair<int, int>> *adj;

    public:
        Graph(int n) {
            this->n = n;
            adj = new vector<pair<int, int>>[n+1];
        }

        void addEdge(int a, int b, int w) {
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});

        }

        /*
        Time Complexity: The time complexity of the above code/algorithm looks O(V^2) as there are two nested 
        loops. If we take a closer look, we can observe that the statements in inner loop are executed O(V+E) times 
        (similar to BFS). The inner loop has decreaseKey() operation which takes O(LogV) time. So overall time complexity 
        is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV) 
        */

        vector<int> dijkstra(int s) {
            vector<int> distance(n+1, INT_MAX);
            bool traversed[n+1] = {0};
            
            // dist, node
            // priority based on dist
            priority_queue<pi, vector<pi>, greater<pi>> minHp;
            
            distance[s] = 0;
            minHp.push({0, s});

            while(!minHp.empty()) {
                // extract min
                auto minNode = minHp.top();
                int cur_dist = minNode.first;
                int cur = minNode.second;

                minHp.pop();

                if(traversed[cur]) continue;

                traversed[cur] = 1; 
                for(auto ad: adj[cur]) {
                    int neigh = ad.first;
                    int w = ad.second;

                    // relaxation
                    if(distance[neigh] > distance[cur] + w ) {
                        distance[neigh] = distance[cur] + w;

                        minHp.push({distance[neigh], neigh});
                    }
                }

            }

            return distance;
        }
};



int main() {
    Graph g(9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(1, 2, 8);
    g.addEdge(7, 8, 7);
    g.addEdge(7, 6, 1);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 5, 14);
    g.addEdge(6, 5, 2);
    g.addEdge(8, 6, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 9);
    g.addEdge(5, 4, 10);


    vector<int> d = g.dijkstra(0);

    cout<<endl;
    for(int i = 0; i < 9; ++i) cout<<d[i]<<" ";

    return 0;
}
