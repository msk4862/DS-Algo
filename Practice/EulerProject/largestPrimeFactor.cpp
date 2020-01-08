#include<iostream>
#include<cmath>
using namespace std;

#define ll long long

ll primes[100];

void findPrime() {

    int ar_size = 100;
    bool isPrime = true;

    ll num = 2;
    int k = 0;
    while (k < ar_size)
    {
        isPrime = true;
        for(ll i =2; i<= sqrt(num); ++i) {
            if(num%i==0) {
                isPrime = false;
                break;           
            }
        }
        if (isPrime)
        {
            primes[k++] = num;
        }

        num++;
        
    }
    
}

int largestPrimeFactor(long n) {
    int i = -1;
    while(n>1)
    {
        i++;
        while(n%primes[i] == 0) {
            n/= primes[i];
        }
        
    }
    
    return primes[i];

}

int main() {
    findPrime();
    
    long n;
    cout<<"Enter no.";
    cin>>n;
    cout<<largestPrimeFactor(n);
    return 0;

}
