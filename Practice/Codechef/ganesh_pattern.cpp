#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            //upper half
            if(i < t/2) {
                if(j==0 || j == t/2) {
                    cout<<"*";
                }
                else if(i ==0 && j > t/2) {
                    cout<<"*";
                }
                else {
                    cout<<" ";
                }
            }
            else if(i==t/2) {
                cout<<"*";
            }
            //lower half
            else {
                if(j==t-1 || j == t/2) {
                    cout<<"*";
                }
                else if(i ==t-1 && j < t/2) {
                    cout<<"*";
                }
                else {
                    cout<<" ";
                }
            }
        }
        cout<<"\n";
    }
    
}