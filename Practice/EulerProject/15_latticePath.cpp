#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
#define ll long long int


// ll factorial[10000000] = {0};

ll fact(ll n) {
    //memotized version

    // if (factorial[n] == 0) {
    //     factorial[n] =  n*fact(n-1);
    // }
    // return factorial[n];

    if(n<=2) {
        return n;
    }
    else {
        return n*fact(n-1); 
    }
}

ll latticePath(int n) {

    int totalMoves = 2*n;
    int num_right = n;
    int num_left = n;

    ll res = fact(totalMoves)/(pow( fact(num_left), 2));

    return res;

    
}

int main() {    

//     factorial[0] =1;
//     factorial[1] =1;
// factorial[2] =2;

    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<latticePath(n);
    return 0;

}
