#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int

long find_gcd(ll a, ll b) {

    while(a!=0 && b != 0) {
        if(a<=b) {
            b %= a;
        } else {
            a %= b;
        }
    }

    return (a == 0)?b:a;

}

int main() {
    ll a, b;
    cin>>a>>b;
    
    cout<<find_gcd(a, b);
}