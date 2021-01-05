// https://www.geeksforgeeks.org/merge-two-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void mergeSorted1(vector<int> ar1, vector<int> ar2) {
	int p1 = 0, p2=0;
	vector<int> res;
	
	while (p1 < ar1.size() && p2 < ar2.size()) {
		if(ar1[p1] < ar2[p2]) {
			res.push_back(ar1[p1]);
			p1++;
		}
		else {
			res.push_back(ar2[p2]);
			p2++;	
		}
	}
	
	while(p1 < ar1.size()) {
		res.push_back(ar1[p1]);
		p1++;
	}
	
	while(p2 < ar2.size()) {
		res.push_back(ar2[p2]);
		p2++;
	}
	
	// either return resultant array 
	// or just overwrite the the values of ar1 and ar2 with the resultant array values
}


void insertionSort(vector<int> &ar) {
	int key = ar[0];
	int i = 1;
	while(i < ar.size() && key > ar[i]) {
		ar[i-1] = ar[i];
		i++;
	}
	
	// put in right place
	ar[i-1] = key;
}

void mergeSorted2(vector<int> ar1, vector<int> ar2) {
	for(int  i = 0; i < ar1.size(); ++i) {
		if(ar1[i] > ar2[0]) {
			int t = ar1[i];
			ar1[i] = ar2[0];
			ar2[0] = t;
			
			// to place 1st swapped element in ar2 in the order
			// as all other are already
			// Time: O(m)
			insertionSort(ar2);
		} 
	}
	
	// now all elemnts in ar2 are greater than ar1
}

void solve() {   
	// 1st: put elements of both arrays in a signgle separated array and sort that array
	// Time COmplexity: O((n+m)log(n+m)), Space COmplexity: o(n+m)
	
	// 2nd approach
	// Time COmplexity: O(n+m), Space Complexity:O(n+m)
	mergeSorted1();
	
	// 3rd approach
	// Time: O(n*m), Space: O(1)
	mergeSorted2();
	
	// 4th approach: Gap Method
	// Time: O((n+m)log(n+m)), Space: O(1) 
	mergeSorted3();
}

int main() {
    solve();
    return 0;
}
