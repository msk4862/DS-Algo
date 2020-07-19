#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

pair<char, int> max_el(unordered_map<char, int> a) {
    pair<char, int> largest = *a.begin();

    for(auto e:a) {
        if(e.second >= largest.second) {
            if(e.second > largest.second) {
                largest = e;
            }
            else if(e.first < largest.first)
                largest = e;
        }
    }

    return largest;
}

void solve() {
    string str;
    cin>>str;

    unordered_map<char, int> c;

    for (int i = 0; i < str.length(); i++) {
        if(c[str[i]])    
            c[str[i]]++;
        else 
            c[str[i]] = 1;   
    }


    pair<char, int> res = max_el(c);
    cout<<res.second<<" "<<res.first<<"\n";
    
}

int main() {
    // FASTIO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}