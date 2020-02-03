#include<bits/stdc++.h>
#include <cstring> 

using namespace std;

int main() {
    int n;

    cin>>n;
    while(n) {
        vector<int> total_x(n, 0);

        string row;
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            getline(cin, row);
            for(int j = 0; j< row.size(); ++j) {
                if(row[j] == 'X') {
                    total_x[i]++;
                }
            }
        }

        int voids = 0;
        int max_X = *max_element(total_x.begin(), total_x.end());

        for(int i = 0; i< n; ++i) {
            voids += max_X-total_x[i];
        }
        printf("%d\n",voids);
        
        cin>>n;
    }
    



}