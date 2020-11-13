#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// is it possible
bool isPossible(int arr[], int n, int pages, int people) {
    int numP = 0;

    int pagesRead = 0, curPeople=1;
    int  i = 0;
    while(i < n) {
        if(pagesRead + arr[i] <= pages) {
            pagesRead += arr[i];    
        }
        else {
            pagesRead = arr[i];
            curPeople++;

            if(curPeople > people) return false;
        }
        i++;
    }
    return true;

}

int findMinPages(int arr[], int n, int people) {
    int minPages = arr[0];
    int maxPages = accumulate(arr, arr+n, 0);

    int s =minPages, e = maxPages;

    int ans = 0;
    while(s <= e) {
        int mid = (e-s)/2 +s;

        if(isPossible(arr, n, mid, people)) {
            // minimize sum
            e = mid-1;
            ans = mid;
        }
        else {
            s=mid+1;
        }
    }

    return ans;
}

void solve() {
    int n = 4;
    int people = 2; 
    int arr[] = {12, 34, 67, 90}; 

    cout<<findMinPages(arr, n, people);

}

int main() {
    FASTIO
    solve();
    return 0;
}