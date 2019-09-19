#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    int t;
    cin>>t;

    while (t--)
    {   
        int n;
        cin>>n;

        if(n == 1) {
            int d;
            cin>>d;
            cout<<"0"<<endl;
        }

        else {
            vector<int> shops(n);
            for (size_t i = 0; i < n; i++)
            {
                cin>>shops[i];
            }

            sort(shops.begin(), shops.end());
            
            int sum = 0, distance = 0;

            for (size_t i = 0; i < n; i++)
            {
                sum += shops[i];
            }
            int parking_pos = ceil(sum/n);

            for (size_t i = 0; i < n-1; i++)
            {
                distance += shops[i+1]-shops[i];
            }
            distance += abs(parking_pos - shops[0]) + abs(parking_pos-shops[n-1]);

            cout<<distance<<endl;
        }
        
    }
    
}