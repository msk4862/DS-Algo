#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
#define REP(i,a,b) for (int i = a; i <= b; i++)

    bool isHappy(int n) {
        unordered_set<int> nums;
        int sum, k;
        while(n != 1) {
            k = n;
            sum = 0;
            while(k>0) {
                int r = k%10;
                sum += r*r;
                k = k/10;
            }
            // cout<<sum<<endl;
            if(nums.count(sum)>0) {
                return false;
            } else {
                nums.insert(sum);
            }
            
            n = sum;
        }
        
        return true;
    }

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        cout<<isHappy(n);
        
    }
}