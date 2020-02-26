#include<iostream>
#include<cstring>

using namespace std;

string reverse(string str, string rev="") {
    if(str == "") {
        return rev;
    } else {
        rev = str.substr(0, 1) + rev;
        str = str.substr(1);

        return reverse(str, rev);
    }
}

int main() {
    string str;
    cout<<"Enter string: ";
    cin>>str;

    cout<<reverse(str);
}