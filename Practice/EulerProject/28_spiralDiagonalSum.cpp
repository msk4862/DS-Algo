
#include <iostream>
#include <algorithm>
using namespace std;

#define lli unsigned long long int 

lli calcSpiralSum(lli N) {

    lli mod = 1000000007;
    //sum of series of ap common difference a0*n+d0*n(n-1)/2+d*n(n-1)*(n-2)/6 
    // d0 = a1 -a0, d = d of ap common difference
    lli sum = 0;

    //1st diagonal sum
    sum = (N + N*(N-1) + (N*(N-1)*(N-2))/3);

    //2nd diagonal sum
    lli tEven = N/2;
    //sum of even no.
    sum += ((2*tEven*(tEven+1)*(2*tEven +1))/3) + tEven*1;

    //sum of odd no.
    lli tOdd = N-tEven;
    sum += ((tOdd*(2*tOdd+1)*(2*tOdd -1))/3);

    // lli n = N/2;
    // return 2*n*(8*(n*n)/3 + 5*n + 13/3) + 1;/

    return sum-1;

}

int main() {

    long t;
    cin>>t;
    lli num;

    while(t--){

        cin>>num;
        cout<<calcSpiralSum(num)%(1000000007)<<endl;
    }

    return 0;
}
