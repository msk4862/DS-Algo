#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

int main() {
    int t, n;
    cin>>t;

    ull c;


    while (t--) {
        cin>>n>>c;

        ull candyNeeded = 0;
        int a;
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            candyNeeded += a;
        }
        
        if(candyNeeded <= c) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}