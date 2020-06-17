#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr); \

bool compare(pair<ll, ll> t1, pair<ll, ll> t2) {
    return t1.second < t2.second;
}

vector<ll> minPoints(pair<ll, ll> times[], ll n) {
    vector<ll> points;

    sort(times, times + n, compare);

    ll curPoint = times[0].second;
    points.push_back(curPoint);

    for (int i = 1; i < n; ++i) {
        if (times[i].first <= curPoint && times[i].second >= curPoint) {
            continue;
        } else {
            curPoint = times[i].second;
            points.push_back(curPoint);
        }
    }

    return points;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;

        pair<ll, ll> timings[n]; 
        for (int i = 0; i < n; ++i) {
            cin>>timings[i].first>>timings[i].second;
        }
        vector<ll> res = minPoints(timings, n);

        cout<<res.size()<<"\n";
        for(auto e: res) {
            cout<<e<<" ";
        }
        cout<<"\n";
    }
    return 0;
}