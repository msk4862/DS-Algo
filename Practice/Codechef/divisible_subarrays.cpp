#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int

int frequency[100001];

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        memset(frequency, 0, sizeof(frequency));
        frequency[0] = 1;

        ll ar[n];
        ll sum = 0;

        for (int i = 0; i < n; i++) {

            cin>>ar[i];
            sum+= ar[i];
            sum = sum%n;
            if(sum < 0) {
                // handling negative remainders
                sum += n;
            }
            frequency[sum]++;
            
        }

        
        /*
            for a subarray ath index to bth index
            Need to find (sum_till_b'th - sum_till_a'th)%N = 0
            (b-a)%N=0
            b%N=a%N
            Need to count where cummulative sum modulo is same(frequency is atleast 2)
            find all possible arrays that can be made by calculating fC2
        */

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll m = frequency[i];
            ans+= (m)*(m-1)/2;
        }
        
        cout<<ans<<"\n";

        
    }
}