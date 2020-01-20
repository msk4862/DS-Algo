#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll unsigned long long int

int main() {
    
    ll t, x,k, y, n, rem;
    cin>>t;

    while (t--) {
        cin>>x>>y>>k>>n;

        rem = x-y;
        bool possible=false;
        

        vector< vector<int> > det(n, vector<int> (2));
        for (int i = 0; i < n; i++)
        {
            cin>>det[i][0]>>det[i][1];

            if(rem <= det[i][0] && k >= det[i][1]) {
                possible  = true;
            }
        }

        if (possible)
        {
            cout<<"LuckyChef\n";
        } else {
            cout<<"UnluckyChef\n";
        }
        
        

    }
}