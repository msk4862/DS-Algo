#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    //finding number occurences of 5 (factor of 10)

    int i = 1;
    long five_counts = 0;

    double current = floor(n/pow(5, i));
    while(current != 0) {
        five_counts += (long) current;
        ++i;
        current = floor(n/pow(5, i));
    }

    cout<<five_counts;
}