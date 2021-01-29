// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

vector<int> maxAllSubarray(int arr[], int n, int k) {
	deque<int> maxEl;
	
    int end;
    // process first window	
    // storing the values maintaining descending order 
    for (end = 0; end < k; end += 1) {
        // if new element is greater
        while(!maxEl.empty() && nums[maxEl.back()] < nums[end]) {
            maxEl.pop_back();
        }
        maxEl.push_back(end);
    }
    

    vector<int> res;
    for (int start = 1; start <= n-k+1; start += 1) {            
        res.push_back(nums[maxEl.front()]);

        // shrink from front 
        // window have been moved to right
        while(!maxEl.empty() && maxEl.front() < start) {
            maxEl.pop_front();
        }

        // extend from back
        // remove lower values from back if new value is greater	
        while(end<n && !maxEl.empty() && nums[maxEl.back()] <= nums[end]) {
            maxEl.pop_back();
        }
        
        maxEl.push_back(end);
        end++;	
    }

    return res;
}

void solve() {   
	int n = 9, k = 3;
	//cin>>n>>k;
	int arr[n] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	/*for (int i = 0; i < n; i += 1) {
		cin>>arr[i];
	}*/
	
	vector<int> res = maxAllSubarray(arr, n, k);
	for(int e: res) cout<<e<<" ";
}

int main() {
    FASTIO
    solve();
    return 0;
}
