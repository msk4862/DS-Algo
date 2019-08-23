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