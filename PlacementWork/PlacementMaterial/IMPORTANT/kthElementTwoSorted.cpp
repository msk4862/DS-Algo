// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int kthElement1(vector<int>& nums1, vector<int>& nums2, int k) {
	int n1 = nums1.size();
	int n2 = nums2.size();

	int i = 0, j = 0;
	while(i < n1 && j < n2) {
		if(k == 1) return min(nums1[i], nums2[j]);

		if(nums1[i] <= nums2[j]) i++;
		else j++;
		k--;
	}

	while(i < n1) {
		if(k == 1) return nums1[i];
		i++;
		k--;
	}

	while(j < n2) {
		if(k == 1) return nums2[j];
		j++;
		k--;
	}

	return -1;
}

int countLessNums(vector<int>& nums1, vector<int>& nums2, int val) {
	/*
		Returns values that are equal or smaller than val
	*/
	
	int count  =0;
	count += upper_bound(nums1.begin(), nums1.end(), val) - nums1.begin();
	count += upper_bound(nums2.begin(), nums2.end(), val) - nums2.begin();

	return count;
}

int kthElement2(vector<int>& nums1, vector<int>& nums2, int k) {
	int n1 = nums1.size();
	int n2 = nums2.size();

	int minV, maxV;

	if(n1 > 0 && n2 > 0) {
		minV = min(nums1[0], nums2[0]);
		maxV = max(nums1[n1-1], nums2[n2-1]);
	}
	// if any of the array is empty
	else if(n1 > 0) {
		minV = nums1[0];
		maxV = nums1[n1-1];
	}
	else {
		minV = nums2[0];
		maxV = nums2[n2-1];
	}

	while(minV <= maxV) {
		int mid = (maxV-minV)/2 + minV;

		int count = countLessNums(nums1, nums2, mid);
		if(count < k) minV = mid+1;
		else maxV = mid-1;
	}

	return minV;
}

void solve() {   
	vector<int> nums1 = {2, 3, 6, 7, 9};
	vector<int> nums2 = {1, 4, 8, 10};

	// 1 indexed
	int k = 5;	/*
	Brute force appoach:
	Store all elements in an array and sort that array 
	and return kth elem
	time: O((m+n)log(m+n)), space: O(m+n)
	*/

	/*
	Optimisation 1: 
	use merge method to merge two sorted arrays
	
	Time: O(m+n), Space: O(m+n)
	*/

	/*
	Optimisation 2: 
	use merge method to merge two sorted arrays
	without storing any value
	
	Time: O(m+n), Space: O(1)
	*/
	cout<<kthElement1(nums1, nums2, k)<<endl;


	/*
	
	Optimisation 3:
	Using binary search (like matrixMedian problem)
	Time: O(m+n), Space: O(1)
	*/
	cout<<kthElement2(nums1, nums2, k)<<endl;

}

int main() {
    FASTIO
    solve();
    return 0;
}