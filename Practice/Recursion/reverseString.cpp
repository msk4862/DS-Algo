#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

string revString(string str) {
    if(str ==  "")
        return str;
    
    return str[str.length()-1] + revString(str.substr(0, str.length()-1));
}



int main() {
    string str;
    cin>>str;

    cout<<revString(str);

    return 0;
}