#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ll t, n, temp, bits = 0;

    cin>>t;

    while (t--)
    {
        cin>>n;

        temp = n;

        while (temp)
        {
            bits = bits | 1<<(temp%10);
            temp/=10;
        }

        if (bits == (1<<10)-1) {
            printf("Contains all digit\n");
        } else {
            printf("False\n");
        }
        
    }
    
}#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ll t, n, temp, bits = 0;

    cin>>t;

    while (t--)
    {
        cin>>n;

        temp = n;

        while (temp)
        {
            bits = bits | 1<<(temp%10);
            temp/=10;
        }

        if (bits == (1<<10)-1) {
            printf("Contains all digit\n");
        } else {
            printf("False\n");
        }
        
    }
    
}