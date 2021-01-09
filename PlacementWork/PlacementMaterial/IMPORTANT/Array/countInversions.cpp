#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int inversions = 0;

void merge(int arr[], int s, int m, int e) {
	int n1 = m - s + 1;
    int n2 = e - m;

	int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[s + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
    
    int  i = 0, j = 0, k = s;   
    
    while (i < n1 && j < n2) {
    	if (L[i] > R[j]) {
    		// rest of elements of L[i] will also form a inversion pair 
    		// because they are left and larger than R[j]
    		inversions += n1-i;

    		arr[k++] = R[j++];
    	}
    	else arr[k++] = L[i++];
    	
    }
    
    while(i < n1) {
    	arr[k++]  = L[i++];
    }

    while(j < n2) {
    	arr[k++]  = R[j++];
    }
}

void mergeSort(int ar[], int s, int e) {
	if(s < e) {
		int m = (e - s)/2 + s;
		
		mergeSort(ar, s, m);
		mergeSort(ar, m+1, e);
		merge(ar, s, m, e);
	}
}

void solve() {
	int n = 5;   
	int ar[] = { 1, 20, 6, 4, 5 };
	
	mergeSort(ar, 0, n-1);

	cout<<inversions<<"\n";
}

int main() {
    FASTIO
    solve();
    return 0;
}
