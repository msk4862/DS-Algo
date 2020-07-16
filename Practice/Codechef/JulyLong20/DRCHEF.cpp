#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll solve() {
    ll n, x;
    cin>>n>>x;

    vector<ll> people(n);
    ll start = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        cin>>people[i];
    }

    sort(people.begin(), people.end());

    // calculating starting city
    for (; start+1 < n and x > people[start]; start++);

    if(start > 0) {

        ll tempx = x, days1 = 0;
        while(tempx < people[start]) {
            days1++;
            tempx<<=1;
        }

        // if largest curable city is cured first
        ll days2 = 1;
        tempx =  people[start-1]*2;
        while(tempx < people[start]) {
            days2++;
            tempx<<=1;
        }

        if(days2 <= days1) 
            start -=1;

    }
    
    ll i = start;
    // cities with people[i] > x
    while (i < n) {
        ans+=1;

        if(x >= people[i]) {
            x = people[i];
            people[i] = 0;
            i++;
        }
        x<<=1;
    }
    
    // adding cities with people[i] < x (that takes only 1 day each)
    return ans+(start);

}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        cout<<solve()<<"\n";
    }
    return 0;
}