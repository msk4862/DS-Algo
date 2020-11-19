#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// https://leetfree.com/problems/sort-transformed-array.html

int calc(int x, int a, int b, int c) {
	return a*x*x + b*x + c;
}

void solve() {   
	int n;
	cin>>n;
	int x[n];
	for(int i = 0; i < n; ++i) {
		cin>>x[i];
	}
	
	int a,b,c;
	cin>>a>>b>>c;
	
	
	vector<int> res;
	int left = 0, right = n-1;	
	
	// to handle inverse parabola
	if(a > 0) {
		// fill in decreasing order
		while(left <= right) {
			if(calc(x[left], a, b, c) < calc(x[right], a, b, c)) {
				res.insert(res.begin(), calc(x[right], a, b, c));
				right--;
			}
			
			else {
				res.insert(res.begin(), calc(x[left], a, b, c));
				left++;	
			}
		}
	}
	else {
	// fill in increasing order
		while(left <= right) {
			if(calc(x[left], a, b, c) < calc(x[right], a, b, c)) {
				res.push_back(calc(x[left], a, b, c));
				left++;
			}
			
			else {
				res.push_back(calc(x[right], a, b, c));
				right--;	
			}
		}
	
	}
	
	for(int i = 0; i < n; ++i) {
		cout<<res[i]<<" ";
	}
	
}

int main() {
    FASTIO
    solve();
    return 0;
}
