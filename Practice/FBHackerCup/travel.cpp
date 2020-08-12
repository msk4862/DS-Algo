#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve(int t) {
    int n;
    cin>>n;
    string arv, dep;
    cin>>arv>>dep;

    char res[n][n];

    // departure not allowed
    for(int i = 0; i < n; ++i) {
        if(dep[i] == 'N') {
            for (int j = 0; j < n; j++) {
                if( i==j) {
                    res[i][j] = 'Y';
                    continue;
                }
                res[i][j] = 'N';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if(dep[i] == 'Y') {
            for (int j = i; j >= 0; j--) {
                if(i == j) {
                    // cout<<i<<" asas as";
                    res[i][j] = 'Y';
                    continue;
                }

                if(arv[j] == 'Y') {
                    // not an adjancent country
                    if(abs(i-j) > 1) {
                        // can travel to its adjacent country and dept is also allowed from there
                        if(res[i][j+1] == 'Y' and dep[j+1] == 'Y')
                            res[i][j] = 'Y';
                        else
                            res[i][j] = 'N';
                    }
                    // adj country
                    else 
                        res[i][j] ='Y';
                }
                // arrrival not allowed
                else {
                    res[i][j] = 'N';
                }

            }
        }
    }

    for (int i = 0; i < n; i++) {
        if(dep[i] == 'Y') {
            for (int j = i+1; j < n; j++) {

                if(arv[j] == 'Y') {
                    // not an adjancent country
                    if(abs(i-j) > 1) {
                        // can travel to its adjacent country and dept is also allowed from there
                        if(res[i][j-1] == 'Y' and dep[j-1] == 'Y')
                            res[i][j] = 'Y';
                        else
                            res[i][j] = 'N';
                    }
                    // adj country
                    else 
                        res[i][j] ='Y';
                }
                // arrrival not allowed
                else {
                    res[i][j] = 'N';
                }

            }
        }
    }

    
    cout<<"Case #"<<t<<":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<res[i][j];
        }
        cout<<"\n";
    }

}

int main() {
    FASTIO;
    int t;
    cin>>t;
    for(int i =1; i <= t; i++) {
        solve(i);
    }
    return 0;
}