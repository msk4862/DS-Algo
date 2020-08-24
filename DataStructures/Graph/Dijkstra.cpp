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
    Graph g(5);

    g.addEdge(1, 2, 5);
    g.addEdge(1, 4, 9);
    g.addEdge(1, 5, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 2);

    vector<int> d = g.dikistra(1);

    for(int i = 1; i <=5; ++i) cout<<d[i]<<" ";

    return 0;
}