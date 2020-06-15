#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin>>t;
        
    
    while(t--) {
        cin>>n;
        int q[n], change, cur_money;
        bool flag = 1;
        int coins[3] = {0};

        for (int i = 0; i < n; i++) {
            cin>>q[i];
        }
        
        for (int i = 0; i < n; i++) {
            change = q[i]-5;
            
            // cout<<coins[0]<<" "<<coins[1]<<" "<<coins[2]<<endl;
            if(change == 10) {
                coins[2]++;
                if(coins[1] >= 1) {
                    coins[1]-= 1;
                }
                else if(coins[0] >= 2) {
                    coins[0]-=2;
                } else {
                    flag=0;
                }
            }
            else if (change == 5) {
                coins[1]++;
                if(coins[0] > 0) {    
                    coins[0]-= 1;
                } else {
                    flag=0;
                }
            } 
            else {
                coins[0] ++;
            }
            
        }
        
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;
}
