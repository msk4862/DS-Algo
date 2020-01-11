#include<iostream>
#include<cmath>

using namespace std;

#define ll long long

ll primeSum(ll n) {

    ll primes[n];

    for (ll i = 0; i < n; i++)
    {
        primes[i] = i;
    }
    primes[1] = 0;

    for (ll i = 2; i < sqrt(n); i++)
    {
        if(primes[i] !=0) {
            for (ll j = 2; i*j < n; j++)
            {
                primes[i*j] = 0;
            }
        } 
    }
    
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum+= primes[i];
    }    
    return sum;
    
}


int main() {    
    ll n;
    cout<<"Enter no.";
    cin>>n;
    cout<<primeSum(n);
    return 0;

}
