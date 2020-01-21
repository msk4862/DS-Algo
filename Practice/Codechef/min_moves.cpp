#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll unsigned long long int

int main() {
    
    ll t, n, moves;
    cin>>t;

    while (t--) {
        cin>>n;   

        ll sum = 0;     

        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin>>w[i];
            sum+= w[i];

        }
        ll min = w[0];
        for(int i = 0; i< n; ++i) {
            if(min > w[i]) {
                min = w[i];
            }
        }

        
        //intead of adding 1 to N-1, decreasing 1 at a time
        cout<<sum-n*min<<"\n";
        

    }
}