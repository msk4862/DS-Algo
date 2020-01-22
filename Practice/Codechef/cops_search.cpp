#include <iostream>
#include <vector>
#include<algorithm>
#include <numeric>    

using namespace std;


int main() {
    
    int t, x, y, m, houseSearched, safe;
    cin>>t;

    while (t--) {
        cin>>m>>x>>y;  
        
        vector<int> houses(100, 1);


        vector<int> arr(m);
        for (int i = 0; i < m; i++) {
            cin>>arr[i];
        }
        
        sort(arr.begin(), arr.end());

        houseSearched = x*y;

        for (int i = 0; i < m; i++)
        {
            int s = max(arr[i]-houseSearched, 1);
            int e = min(arr[i]+houseSearched, 100);
            for (int j = s-1; j < e; j++)
            {
                houses[j] = 0;
            }
        }

        safe = 0;
        cout<<accumulate(houses.begin(), houses.end(), safe)<<"\n";
        
    }
}