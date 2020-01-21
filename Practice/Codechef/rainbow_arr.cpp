#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll unsigned long long int

int main() {
    
    ll t, n;
    cin>>t;

    while (t--) {
        cin>>n;   
        bool isRainbow = true;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin>>arr[i];

            if (arr[i] <= 0)
            {
                isRainbow = false;
            }
        }

        ll maxElm = *max_element(arr.begin(), arr.end());

        if (!isRainbow || maxElm != 7 || arr[0] != 1)
        {
            printf("no\n");
            continue;
        }
        


        for (int i = 0; i < n/2; i++) {
            if (arr[i] != arr[n-i-1] || (arr[i] - arr[i+1] != 0 && arr[i] - arr[i+1] != -1)) {
                    isRainbow = false;
                    break;
                
            }
            
        }
        
        if (isRainbow)
        {
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
            
    }
}