#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


class Graph{
    ll n;
    vector<ll> *adj;
    public:
        vector<ll> popul;
        vector<ll> num_fruit;

        bool *travelled;
        ll *final_fruits;

        Graph(ll n) {
            this->n = n;
            adj = new vector<ll>[n];
            
            final_fruits = new ll[n];
            travelled = new bool[n];

            for (int i = 0; i < n; i++) {
                final_fruits[i] = -1;
                travelled[i] = 0;
            }            
        }

        void addEdge(ll u, ll v) {
            // adj[u].push_back(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void dfs(ll v, ll pi, ll day, bool visited[]) {
            visited[v] = 1;

            if(num_fruit[v] > 0) {
                num_fruit[v] -= min(num_fruit[v], pi);
                if(num_fruit[v]==0) final_fruits[v] = day;
            }
            for( ll ad: adj[v]) {
                if(!visited[ad] and !travelled[ad])
                    dfs(ad, pi, day, visited);
            }
        }

        void travel(ll u, ll day) {
            bool visited[n] = {0};
            if(num_fruit[u] > 0)
                dfs(u, popul[u], day, visited);
            travelled[u] = 1;
        }
};

void solve() {
    ll n;
    cin>>n;
    Graph g(n);

    ll u, v, day[n], pop, fruits;
    for (int i = 0; i < n-1; i++) {
        cin>>u>>v;
        g.addEdge(u-1, v-1);
    }
    for (int i = 0; i < n; i++) {
        cin>>day[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>pop;
        g.popul.push_back(pop);
    }
    for (int i = 0; i < n; i++) {
        cin>>fruits;
        g.num_fruit.push_back(fruits);
    }


    for (int i = 0; i < n; i++) {
        g.travel(day[i]-1, i+1);
    }
    
    
    for (int i = 0; i < n; i++) {
        cout<<g.final_fruits[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}