#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int solve() {
    string ar;
    getline(cin, ar);

    vector<int> nums;
    char* num;
    num = strtok((char*) ar.c_str(), " ");
    while(num) {
        nums.push_back(stoi(num));
        num = strtok(NULL, " ");
    }

    sort(nums.begin(), nums.end());

    // for(int i = 0; i < nums.size(); ++i) 
    //     cout<<nums[i]<<" ";

    return nums[1];
    
}

int main() {
    // FASTIO;
    int t;
    cin>>t;
    cin.ignore();
    while(t--) {
        cout<<solve()<<"\n";
    }
    return 0;
}