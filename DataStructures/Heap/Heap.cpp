#include<bits/stdc++.h>
using namespace std;

class Heap {
	vector<int> h;
	bool isMinHeap;
	
	bool compare(int parent, int cur) {
		if(isMinHeap) return parent > cur;
		return parent < cur;
	}
	
	
	void heapify(int i) {
		
		int left = 2*i;
		int right = 2*i + 1;
		
		// assuming cur is minimum
		int minInd = i;
		
		// compare with left child
		if(left < h.size() && compare(h[minInd], h[left]) ) minInd = left;
	
		// compare with right child
		else if(right < h.size() && compare(h[minInd], h[right])) minInd = right;
		
		if(minInd != i) {
		// swap min element with cur ith index
			int temp = h[minInd];
			h[minInd] = h[i];
			h[i] = temp;
			
			heapify(minInd);
		}
	}			
	
	public:
		Heap(bool type = true) {
			isMinHeap = type;
			// not going to use 0th index
			h.push_back(-1);
		}

		void push(int val);
		int top();
		void pop();
		int size();

};

int Heap::size() {
// excluding 0th index
	return h.size()-1;
}

void Heap::push(int val) {
	// insert at last index
	h.push_back(val);
	
	// restore heap property if violated
	int curInd = h.size()-1;
	int parent = curInd/2;
	
	while(parent >= 1 && compare(h[parent], h[curInd])) {
			int temp = h[parent];
			h[parent] = h[curInd];
			h[curInd] = temp;
			
			curInd = parent;
			parent = parent/2;
	}
}


int Heap::top() {
	return h[1];
}


void Heap::pop() {
	// replace the top element with the last value of heap
	// and then remove last element
	h[1] = h[h.size()-1];
	h.pop_back();
	
	heapify(1);
}

int main() {
	Heap minH = new Heap(true);
	
	minH.push(2);
	minH.push(8);
	minH.push(10);
	
	cout<<minH.top()<<" ";
	minH.push(-1);
	minH.push(1);
	
	cout<<minH.top()<<" ";
	minH.push(3);
	
	cout<<minH.top()<<" ";
	
	cout<<endl;
	for(int i = 0; i < minH.size(); ++i) {
		cout<<minH.top()<<" ";
		minH.pop();
	}
}
