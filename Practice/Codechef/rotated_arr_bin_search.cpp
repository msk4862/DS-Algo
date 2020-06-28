#include<bits/stdc++.h>
using namespace std;

int bin_search(vector<int> a, int key) {
    int start = 0;
    int end = a.size()-1;

    // array is divided into two sorted arrays
    while(start <= end) {

        // mid will lie in 1st sorted arr or 2nd sorted arr
        int mid = (end-start)/2 + start;

        if(key == a[mid]) {
            return mid;
        }

        else if(a[start] <= a[mid]) {
            // In 1st sorted array partiton
            if(key > a[start] && key < a[mid]) {
                end = mid-1;
            } else {
                end = mid+1;
            }
        }
        else {
            // In 2nd sorted array partiton
            if(key > a[mid] && key < a[end]) {
                end = mid+1;
            } else {
                end = mid-1;
            }
        }
    }

    return -1;
}


int main() {
    int n;
    cin>>n;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin>>e;
        a.push_back(e);
    }

    int key;
    cin>>key;
    cout<<bin_search(a, key);
    
    
}