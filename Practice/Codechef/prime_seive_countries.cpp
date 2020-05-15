#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const ll N = 1000000;
vector<bool> primes(N+1, true);


int main() {
    int t;
    cin>>t;

    primes[0] = primes[1] = false;
        
    for (int i = 2; i*i <= N; i++)
    {
        if(!primes[i]) {
            continue;
        }

        for (int j = i*i; j <= N; j+=i)
        {
            primes[j] = false;
        }
        
    }

    while(t--) {
        ll a, b;
        cin>>a>>b;
        

        int count_countries = 0;

        for (int i = a; i <= b; i++)
        {
            if(primes[i]) {
                count_countries++;
            }
        }
        cout<<count_countries<<"\n";
        
    }
}