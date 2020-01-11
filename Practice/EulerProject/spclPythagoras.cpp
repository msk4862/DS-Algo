#include<iostream>
using namespace std;

#define ll long long

ll spclTriplets(int n) {

    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (i+j+k == n && i*i + j*j == k*k) {
                    return i*j*k;
                }
            }
            
        }
        
    }
    
}

int main() {    
    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<spclTriplets(n);
    return 0;

}
