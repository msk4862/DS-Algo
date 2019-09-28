#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;

    int i = 1;
    while(t--) {
        int l, w, h;
        cin>>l>>w>>h;

        if (l <= 20 && w <= 20 && h <=20)
        {
            cout<<"Case "<<i<<": "<<"good"<<endl;
        } else
        {
             cout<<"Case "<<i<<": "<<"bad"<<endl;
        }
        
     i++;   
    }
}