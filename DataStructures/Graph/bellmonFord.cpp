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
        }

        vector<int> bellmonFordSS(int src) {
            vector<int> dist(n, INT_MAX); 

            dist[src] = 0;
            for (int i = 0; i < n-1; ++i) {
                for (int u = 0; u < n; ++u) {
                    for(auto ad : adj[u]) {
                        int v = ad.first;
                        int w = ad.second;

                        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
                    }
                }
            }
            return dist;
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


    vector<int> d = g.bellmonFordSS(0);

    for(int i = 0; i < 9; ++i) cout<<d[i]<<" ";
    cout<<endl;

    return 0;
}
