#include<bits/stdc++.h>
using namespace std;

int safePos(int n, int k) {
	// only one person remainig
	if(n == 1)	return 1;

	// changing starting pos
	return (safePos(n-1, k) + k )%n;
}

int main() {


	return 0;
}