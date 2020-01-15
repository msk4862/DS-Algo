#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

vector<int> primes;

void findPrimes() {
    int n = 3000;

    int series[n];

    for (int i = 0; i < n; i++)
    {
        series[i] = i;
    }
    series[1] = 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if(series[i] !=0) {
            for (int j = 2; i*j < n; j++)
            {
                series[i*j] = 0;
            }
        } 
    }

    for(int i = 0; i< n; ++i) {
        if(series[i] != 0)
            primes.push_back(series[i]);
    }
}


bool isPrime(int n) {
    if (n<=1){
        return false;
    }

    for(int i =2; i<= sqrt(n);++i) {
        if((n%i) == 0) {
            return false;
        }
    }
    return true;
}

int checkConsecutivePrime(int a, int b) {

    for(int n = 0; ; ++n) {
        int num = n*n + a*n + b;
        if(!isPrime(num)) {
            return n;
        }
    }
}


int main() {
    
    int n;
    cin>>n;

    findPrimes();

    int max=0, maxA, maxB;

    vector<int> A, B;

    //b must be prime
        //a must be odd (check for n=1)
    for(int i=-n; i <= n; ++i){
        if(i >= 0 && i<primes.size() && primes[i] <= n) {
            B.push_back(primes[i]);
        }

        if(i%2 != 0) {
            A.push_back(i);
        }
    }

    for(int a=0; a < A.size(); ++a){
      for(int b=0; b < B.size(); ++b){
          int numPrimes = checkConsecutivePrime(A[a], B[b]);
          if(max < numPrimes) {
              max = numPrimes;
              maxA = A[a];
              maxB = B[b];
          }
        }   
    } 

    cout<<maxA<<" "<<maxB;
    return 0;
}
