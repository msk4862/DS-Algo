#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll digitSum(ll n) {
    // return to_string(n).length();
    ll sum;
    for (sum = 0; n > 0; sum += n % 10, n /= 10); 
    return sum;
}

int solve(vector<pair<ll, ll>> n) {
    int p1,p2;
    p1= p2= 0;
    
    // cout<<p1<< " " << p2;
    for (int i = 0; i < n.size(); i++) {
        ll a = digitSum(n[i].first);
        ll b = digitSum(n[i].second);
        // cout<<a<<" "<<b<<endl;
        
        if(a == b) {
            p1+=1;
            p2+=1;
        }
        else if(a < b) {
            p2+=1;
        } 
        else {
            p1+=1;
        }
    }
    // cout<<p1<<" "<<p2<<endl;
    if(p1 > p2) {
        cout<<"0 "<<p1;
    }
    else if(p1 < p2) {
        cout<<"1 "<<p2;
    }
    else {
        cout<<"2 "<<p1;
    }
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<pair<ll, ll>> num(n);
        for (int i = 0; i < n; i++) {
            cin>>num[i].first>>num[i].second;
        }
        
        solve(num);
        cout<<"\n";
    }
    return 0;
}