#include<bits/stdc++.h>

using namespace std;
#define ll long long int

string binary(ll A) {

    string bin;
    if(A == 0)
            return "0";

        for (int i = 0; (1<<i) <= A; i++)
        {
            char b ;
            if (A&(1<<i)) {
                b = '1';
            } else {
                b = '0';
            }
            bin = b + bin;
        }
    return bin;
    
}

int main() {
    ll t, n;
    cin>>t;
    while(t-- ) {
        cin>>n;

        cout<<binary(n);
        cout<<endl;
        
        
    }
}

