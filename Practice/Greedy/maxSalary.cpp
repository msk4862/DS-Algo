#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr); \

bool compare(ll n1, ll n2) {

    // if(to_string(n1).length() == to_string(n2).length()) return n1 > n2;

    ll num1 = stoll(to_string(n1)+to_string(n2));
    ll num2 = stoll(to_string(n2)+to_string(n1));

    if(num1 > num2) return true;
    return false;
}


ll calcMaxSalary(vector<ll> nums) {
    
    string maxSal = "";

    sort(nums.begin(), nums.end(), compare);
    for (int i = 0; i < nums.size(); i++) {
        maxSal += to_string(nums[i]);
    }
    return stoll(maxSal);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++) {
            cin>>nums[i];
        }
        

        cout<<calcMaxSalary(nums)<<"\n";

    }
    return 0;
}