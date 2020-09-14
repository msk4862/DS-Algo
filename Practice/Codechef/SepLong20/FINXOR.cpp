#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int solve() {
    ll n;
    cin>>n;

    vector<ll> sums;
    ll gra_ans;
    for (int i = 1; i <= 20; i++) {
        cout<<"1 "<<(1<<i)<<endl;
        cout.flush();
        cin>>gra_ans;
        sums.push_back(gra_ans);
    }
    ll s = sums.size();
    
    reverse(sums.begin(), sums.end());

    ll sum = sums[0]-n*(1<<20);
    for (int i = 1; i < s; i++) {
        if(sums[i] >= sum) {
            sums[i] = ((n-(sums[i]-sum)/(1<<(s-i)))/2);
        }
        else {
            sums[i] = ((n+(sum-sums[i])/(1<<(s-i)))/2);
        }
    }
    
    ll res = 0;
    ll ans;
    for (int i = 1; i < s; i++)
        if(sums[i]%2 !=0) 
            res += (1<<(s-i));
    if(sum%2 !=0)
        res++;
    
    cout<<"2 "<<res<<endl;
    cout.flush();
    cin>>ans;
    
    return ans;    
}

int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--) {
        if(!solve()) break;
        cout.flush();
        cout<<endl;
    }
    return 0;
}