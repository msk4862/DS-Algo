#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


int tsp(int mask, int cur, vector<vector<int>> graph, int n) {
    // all cities are travelled (mask is all 1's)
    if(mask == (1<<n)-1) 
        // cost to return back to origin node
        return graph[cur][0];
    
    // travel an unvisitd city
    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {

        if((mask&(1<<city)) == 0) {
            // markin city as travelled
            mask = mask|(1<<city);
            int cost = graph[cur][city] + tsp(mask, city, graph, n);
            minCost = min(minCost, cost);    
        }
    }

    return minCost;
    
}

int main() {


    int n;
    cin>>n;

    // adjacency matrix (contains weighted)
    vector<vector<int>> graph(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>graph[i][j];
        }
    }

    // mask = 00001
    cout<<tsp(1, 0, graph, n)<<"\n";
            
    return 0;
}