/*
  Single Number
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
#define REP(i,a,b) for (int i = a; i <= b; i++)

int singleElement(vector<int> nums) {
    sort(nums.begin(), nums.end());
        // map<int, int> count;
        int cur = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(cur != nums[i]) {
                if(count == 1) {
                    return cur;
                }
                cur = nums[i];
                count = 1;
            } else {
                count++;
            }
        }
        return cur;

}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {   
            cin>>arr[i];
        }

        cout<<singleElement(arr);
        
    }
}