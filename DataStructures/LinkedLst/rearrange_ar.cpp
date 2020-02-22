#include<iostream>
#include<list>
#include<vector>

using namespace std;

void rearrange(int ar[], int l, int r) {
    if(l >= r) {
        return;
    } else {
        while(ar[l]%2==0 && l < r) {
            l++;
        }
        while(ar[r]%2==1 && l < r) {
            r--;
        }
        if(l<r) {
            int temp = ar[l];
            ar[l] = ar[r];
            ar[r] = temp;
            l++;
            r--;
        }

        rearrange(ar, l, r);
    }
}

int main() {
    int n;
    cin>>n;

    int ar[n];
    for (int i = 0; i < n; i++)
    {   
        cin>>ar[i];
    }

    rearrange(ar, 0, n-1);

    for(int i = 0; i < n; ++i) {
        cout<<ar[i]<<" ";
    }
    
}