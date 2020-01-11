#include<iostream>
#include<cmath>

using namespace std;
#define ll long long

int findFactors(ll n) {

    int numFactors = 2;
    //factors come in pairs
    /*If we look carefully, all the divisors are present in 
    pairs. For example if n = 100, then the various pairs of divisors are:
     (1,100), (2,50), (4,25), (5,20), (10,10)*/

        for(ll i =2; i<=sqrt(n); ++i) {
            if(n%i==0) {
                if(n/i == i) {
                    numFactors+=1;
                }
                else {
                    numFactors +=2;
                }
            }
        
        }
        return numFactors;
    
}


int divisibleTriangleNumber(int n) {
    ll num = 1;
    
    for (ll i = 2;true; ++i)
    {
        num+=i;
        if (n < findFactors(num))
        {
            return num;
        }
        

    }  
    
}

int main() {    
    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<divisibleTriangleNumber(n);
    return 0;

}
