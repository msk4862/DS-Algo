#include<iostream>
#include <vector>

using namespace std;

vector<int> multiply_naive(vector<int> &a, vector<int> &b) {
	int n = 2*a.size()-1;
	vector<int> res(n);

	for (int i = 0; i < n; ++i)
	{
		res[i] = 0;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			res[i + j] += a[i]*b[j];
		}
	}

	return res;
}

int multiply_fast(vector<int> &a, vector<int> &b,int n, int a_low, int b_low) {
	int size = 2*n-1;
	vector<int> res(size);

	if (n == 1) 
	{
		res[0] = a[a_low]*b[b_low];
		return res[0];
	}

	cout<<multiply_fast(a, b, n/2, 0, 0)<< " ";
	cout<< multiply_fast(a, b, n/2, n/2, n/2)<< " ";

	return -1;
}

int main() {
	int n;
	cin>>n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i];
	}

	vector<int> result = multiply_naive(a, b);

	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<" ";
	}

}