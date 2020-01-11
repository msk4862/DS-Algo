#include<iostream>
#include<cmath>
using namespace std;

int sumSquareDifference(int n) {

    long s1 = pow( ((n*(n+1))/2), 2);
    long s2 = (n*(n+1)*(2*n+1))/6;

    return s1-s2;
    
}

int main() {    
    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<sumSquareDifference(n);
    return 0;

}
