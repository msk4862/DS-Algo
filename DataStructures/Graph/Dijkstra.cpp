#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

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

        vector<int> dikistra(int s) {
            vector<int> distance(n+1, INT_MAX);
            distance[s] = 0;
            
            queue<int> q;
            q.push(s);

            bool traversed[n+1] = {0};
            while(!q.empty()) {
                int cur = q.front();
                q.pop();

                if(traversed[cur]) continue;

                for(auto ad: adj[cur]) {
                    int neigh = ad.first;
                    int w = ad.second;
                    if(distance[neigh] > distance[cur] + w ) {
                        q.push(neigh);
                        distance[neigh] = distance[cur] + w;
                    }
                }

                traversed[cur] = 1; 

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


    vector<int> d = g.dikistra(0);

    for(int i = 0; i < 9; ++i) cout<<d[i]<<" ";

    return 0;
}
