#include<bits/stdc++.h>
using namespace std;


void nextGreat(int ar[], int n) {
	stack<int> nums;

	nums.push(ar[0]);
	for (int i = 1; i < n; ++i) {
		int next = ar[i];

		while(!nums.empty() && nums.top() < next) {
			cout<<nums.top()<<"->"<<next<<"\n";
			// top's greater is found
			nums.pop();
		}

		// find greater for current next also
		nums.push(next);
	}

	while(top.empty()) {
		cout<<nums.top()<<"-> -1\n";
		nums.pop();
	}
}

int main() {

	return 0;
}