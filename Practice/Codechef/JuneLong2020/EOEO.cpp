#include <iostream>
#include <cmath>
using namespace std;

#define ll unsigned long long

ll getodd_bit(ll ts) {
    ll mask = 1, moves=0;
    while((ts&mask)==0) {
        mask<<=1;
        moves++;
    }
    
    return moves+1;
}

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        ll ts, js = 0;
        cin>>ts;
        
        if(ts%2 == 1) {
            cout<<ts/2<<"\n";
        }  
        else {
            ll ways=  0;
            ll odd_bit = getodd_bit(ts);
            ll mask = 0b1;

            
            for (int i = 1; i < odd_bit; i++) {
                mask+= (1<<i);
            }
            
            // cout<<mask<<" mask ";
            for (ll i = ts-1; i > 0; i--) {
              if((i&mask)==0) {
                // cout<<i<<" ";
                ways =i/(mask+1);
                break;
                // ways++;
              }
            }
            cout<<ways<<"\n";
        }
    }
    
	return 0;
}
