#include<bits/stdc++.h>

using namespace std;
#define ll long long int

vector<int> repeatedNumber(const vector<int> &A) {
    ll actual, sumA, actual2, sumA2, x, y;
    vector<int> ans(2);
    
    ll n = A.size();
    sumA = accumulate(A.begin(), A.end(), 0);
    actual = ((ll)(n)*(ll)(n+1))/2;
    
    sumA2 = 0;
    for (int i = 0; i < A.size(); ++i) {
        sumA2 += (ll)A[i]*(ll)A[i];
    }
    actual2 = (ll)n*(ll)(n+1)*(ll)(2*n+1)/6;
    
    x = actual - sumA;
    y = (ll)(actual2 - sumA2)/x;
    
    ans[1] = (int)((y+x)/2);
    ans[0] = (int)(ans[1] - x);
    
    return ans;
}

int main() {
    ll t, n;
    cin>>t;
    while(t-- ) {
        cin>>n;
        vector<ll> a(n);

        for (ll i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        vector<int> res = repeatedNumber(a);

        cout<<res[0]<<" "<<res[1]<<endl;
        
    }
}