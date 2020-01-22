#include <iostream>
#include <vector>

using namespace std;

#define ll unsigned long long int

int main() {
    
    ll t, n, count, pairs;

    cin>>t;

    while (t--) {
        cin>>n; 
        count = 0;
        
        string str;
        cin>>str;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
            {
                count++;
                
            }
            
        }
        
        //nC2
        pairs = (count*(count-1))/2;

        cout<<count+pairs<<"\n";
        
    }
}