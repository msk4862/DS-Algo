#include<iostream>
using namespace std;

#define ll long long

ll multiplesOf3and5(ll number) {
    number -= 1;
    ll s1 = ((number/3)/2.0)*(2*3 + (number/3-1)*3);
    

    ll s2 = ((number/5)/2.0)*(2*5 + (number/5-1)*5);

    ll s3 = ((number/(3*5))/2.0)*(2*15 + (number/(3*5)-1)*15);

    return s1+s2-s3;
}

int main() {
    cout<<multiplesOf3and5(19564);
    return 0;

}
