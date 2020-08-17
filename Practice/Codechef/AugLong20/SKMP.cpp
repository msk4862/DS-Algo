#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int bin_search(string str, char v) {
    ll s = 0, l = str.length()-1;

    while(s <= l) {
        ll m = (l-s)/2 + s;

        // cout<<m<<"\n";
        if(str[m] == v) {
            for (m = m+1; m < str.length() && str[m]==v ; m++); 
            return m;   
        }
        else if(str[m] < v) s=m+1;
        else l=m-1;
    }

    return s;
}

void solve() {
    string s, p;
    cin>>s>>p;

    for (int i = 0; i < p.length(); i++) {
        // s[s.find(p[i])] = ''; 
        s.replace(s.find(p[i]), 1, "");
    }

    sort(s.begin(), s.end());

    string org_s = s;

    int  i = bin_search(s, p[0]);

    string ans =  s.insert(i, p);
    // cout<<s<<" "<<org_s<<"\n";

    if(org_s.find(p[0])!= string::npos) {
        // cout<<s<<" "<<"\n";

        ans = min(ans, org_s.substr(0, org_s.find(p[0])) + p + org_s.substr(org_s.find(p[0])));
    }

    cout<<ans<<"\n";
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