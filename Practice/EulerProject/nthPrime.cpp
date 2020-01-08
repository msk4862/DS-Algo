#include<iostream>
#include<cmath>
using namespace std;

#define ll long long

ll findPrime(int n) {

    bool isPrime = true;
    ll num = 1;
    int k = 0;
    while (k < n)
    {
        num++;
        isPrime = true;
        for(ll i =2; i<= sqrt(num); ++i) {
            if(num%i==0) {
                isPrime = false;
                break;           
            }
        }
        if (isPrime)
        {
            k++;
        }

    }

    return num;
    
}

int main() {
    cout<<findPrime(6)<<endl;
    cout<<findPrime(10)<<endl;
    cout<<findPrime(100)<<endl;
    cout<<findPrime(10001)<<endl;

    return 0;

}
