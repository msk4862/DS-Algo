#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    int n;
    cin>>n;

    int v[n];
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    unordered_map<int, vector<pair<int, float>>> c;
    vector<int> infected(n, 0);
    int pos;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if(v[j] != v[i]) { 
                float t = (float) (i-j)/(v[j]-v[i]);
                if(t>0) { 
                    c[i].push_back({j, t}); 
                    c[j].push_back({i, t});
                }
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        set<int> inf;
        for (auto a: c[i]) {
            if(inf.find(a.first)==inf.end()) {
                inf.insert(a.first);
                infected[i]++;
            }
            for(auto o: c[a.first]) {
                if(o.first!= i and inf.find(o.first)==inf.end() and o.second > a.second) {
                    inf.insert(o.first);
                    infected[i]++;
    
                }
            }
        }
        
    }

    // for(auto m:c) {
    //     cout<<m.first<<"->";
    //     for(auto a: m.second) {
    //         cout<<a.first<<":"<<a.second<<", ";
    //     }
    //     cout<<endl;
    // }



    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if(j < i) {
    //             if(v[i] < v[j]) infected[i]++;
    //         } else if(j > i) {
    //             if(v[i] > v[j]) infected[i]++;
    //         }
    //     }
        
    // }

    cout<<*min_element(infected.begin(), infected.end())+1<<" "<<*max_element(infected.begin(), infected.end())+1<<"\n";
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