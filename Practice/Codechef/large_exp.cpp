#include <iostream>
#include <cmath>

using namespace std;

#define ll unsigned long long int

ll calc_pow(ll base, ll exp) {
    ll mod = 1000000007;

    if (exp <= 1) {
        return base;
    } else {
        if (exp%2 == 0) {
            return pow(calc_pow(base%mod, exp/2), 2);
        } else {
            return base*pow(calc_pow(base%mod, (exp-1)/2), 2);
        } 
    }
}

int main() {
    
    ll t, base, exp;
    cin>>t;

    while (t--) {
        cin>>base>>exp;
        
        printf("%d\n", calc_pow(base, exp));
    }
}