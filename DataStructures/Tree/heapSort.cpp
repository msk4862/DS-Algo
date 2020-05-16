#include<iostream>

using namespace std;

void swap(int *Arr,int x,int y){
	int temp = Arr[x];
	Arr[x] = Arr[y];
	Arr[y] = temp;
}

void MaxHeapify(int *Arr,int size,int i){
	
	if(i>=size/2)
		return; // leaf node

	int l = 2*i+1;
	int r = 2*i+2;
	
	int largest = i;
	
	if(l<size && Arr[l]>Arr[largest])
		largest = l;
	if(r<size && Arr[r] > Arr[largest])
		largest =r;
	
	if(largest != i) {
		swap(Arr,largest,i);
		MaxHeapify(Arr,size,largest);
	}
	
}

void BuildMaxHeap(int *Arr,int size){

	// heapify internal nodes
	for(int i=(size/2)-1;i>=0;i--)
		MaxHeapify(Arr,size,i);
}



void HeapSort(int *Arr,int size){
	int heapsize = size;

	BuildMaxHeap(Arr,heapsize);
	
	for(int i=size-1;i>=0;i--) {
		swap(Arr,0,i);
		heapsize--;
		MaxHeapify(Arr,heapsize,0);

	}
}

int main() {

	int size;
	cout<<"\nenter the size of heap\n";
	cin>>size;

	int *arr = new int[size];
	for(int i=0;i<size;i++){
		arr[i] = size-i;
	}

	cout<<"\ninput array :: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	HeapSort(arr,size);

	cout<<"\nsorted array :: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}