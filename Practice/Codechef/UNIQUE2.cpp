// https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
// All elemnts have came twice except 2 unique nums 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {   
	int n;
	cin>>n;
	
	int nums[n];
	for (int i = 0; i < n; i += 1) {
		cin>>nums[i];
	}
	
	int res = 0;
	// all duplicates will get eliminated except a^b (a and b are the two unique nums)
	for (int i = 0; i < n; i += 1) {
		res ^= nums[i];
	}
	
	// take any set bit of a^b (i'm taking rightmost)
	// with idea that kth bit is set means that only one of them (a or b) has its kth bit set. 
	int set_bit_no = res & ~(res-1);
	
	
	int num1 = 0, num2 = 0;
	// divide array into two parttions one with having kth bit set and other with not set
	// now both a and b are separated in diff partitions
	//	now just find unique num in separeted partitions
	for (int i = 0; i < n; i += 1) {
		if(nums[i] & set_bit_no) 
			num1 ^= nums[i];
		else
			num2 ^= nums[i];
	}
	
	cout<<num1<<" "<<num2<<endl;
}

int main() {
    FASTIO
    solve();
    return 0;
}
