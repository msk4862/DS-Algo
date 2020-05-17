#include<bits/stdc++.h>
#include<string>

using namespace std;
#define ll long long unsigned int

string extractTokenFromString(string str, int key) {
    char* s = strtok((char *) str.c_str(), " ");
    while (key > 1) {
        // NULL for using same string as above
        s = strtok(NULL, " ");
        key--;
    }

    return (string) s;
}

bool numericCompare(pair<string, string> str1, pair<string, string> str2) {
    int n1 = stoi(str1.second);
    int n2 = stoi(str2.second);

    return n1<n2;

}

bool lexicalCompare(pair<string, string> str1, pair<string, string> str2) {
    return str1.second<str2.second;
}


int main() {
    int n;
    int key;
    string reverse, ordering;
    cin>>n;
    string s[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }

    cin>>key>>reverse>>ordering;
    
    pair<string, string> str_key_pair[n];

    for (int i = 0; i < n; i++) {
        str_key_pair[i].first = s[i];
        str_key_pair[i].second = extractTokenFromString(s[i], key);
    }

    if(ordering == "numeric") {
        sort(str_key_pair, str_key_pair+n, numericCompare);
    } else {
        sort(str_key_pair, str_key_pair+n, lexicalCompare);
    }
    
    if(reverse == "true") {
        for (int i = 0; i < n/2; i++) {
            swap(str_key_pair[i], str_key_pair[n-i-1]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<str_key_pair[i].first<<"\n";
    }
    
    
}