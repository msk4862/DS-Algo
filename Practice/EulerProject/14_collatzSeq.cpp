#include<iostream>
#include<vector>

using namespace std;
#define ll long long

vector<int> memorize(1000000, 0);

int collatz(ll n) {
    
    if (memorize[n] == 0)
    {
        memorize[n] = 1 + collatz(((n % 2) ? (3 * n + 1) : (n / 2)));

    }
    return memorize[n];        


}

int maxTerms(int n) {
    int max = 0;
    ll max_start = 0;
    memorize[1] = 1;

    

    for (ll i = 2; i < n; i++)
    {   
        int terms = collatz(i);
        if (max < terms){
            max = terms;
            max_start = i;
        }
    }

    return max_start;
    
}

int main() {    
    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<maxTerms(n);
    return 0;

}
