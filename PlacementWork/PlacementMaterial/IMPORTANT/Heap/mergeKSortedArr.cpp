#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

class Element {
public:
	int value;
	int index;
	// index of array (0...k-1) 
	int arrInd;		
	Element(int _value, int _index, int _arrInd) {
		value = _value;
		index = _index;
		arrInd = _arrInd;
	}
};

class Comparator {
public:
	bool operator()(Element a, Element b) {
		// min heap
		return a.value > b.value; 
	}	
};

vector<int> mergeSorted(vector<vector<int>> ar, int k) {
	// {index, ith array}
	priority_queue<Element, vector<Element>, Comparator> pq_min;
	
	vector<int> res;
	for(int i = 0; i < k; ++i) {
		pq_min.push(Element(ar[i][0], 0, i));
	}
	
	while(!pq_min.empty()) {
		// get the minimum value object
		Element minE = pq_min.top();
		
		int curArr = minE.arrInd;
		int index = minE.index;
		int value = minE.value;
		
		res.push_back(value);
		// remove that object
		pq_min.pop();
		
		// if elements left in that current array
		// push that value
		if(index+1 < ar[curArr].size()) pq_min.push(Element(ar[curArr][index+1], index+1, curArr));
	}
	
	return res;
}

void solve() {   
	vector<vector<int>> ar = {
		{0,3,6,8,100},
		{3,7,9,11},
		{1,2},
		{-5,9,10,260}
	};
	
	int k = 4;
	vector<int> res = mergeSorted(ar, k);
	
	for(int e : res) cout<<e<<" ";
}

int main() {
    FASTIO
    solve();
    return 0;
}
