#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while(cin>>n) {
        bool isJolly = true;
        vector<int> ar;
        int max = INT_MIN;
        for(int i = 0; i < n; ++i) {
            int e;
            cin>>e;
            ar.push_back(e);

        }
        vector<int> hash(n-1, 0);

        for(int i = 0; i < ar.size()-1; ++i) {
            int dif = abs(ar[i]-ar[i+1]);
            if(dif <= n && dif > 0)
                hash[dif-1] = 1;
        }
        
        for(int i = 0; i < n-1; ++i) {
            if(hash[i] == 0) {
                isJolly =false;
                break;
            }
        }
        if(isJolly) {
            cout<<"Jolly\n";
        } else {
            cout<<"Not jolly\n";
        }
    }
}