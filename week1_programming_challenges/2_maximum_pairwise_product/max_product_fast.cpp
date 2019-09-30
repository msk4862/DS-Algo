#include <iostream>
#include <vector>
#include <algorithm> //sort()

using namespace std;

//fast algo
long long MaxPairwiseProduct_Fast(vector<int> v) {
	
	int n = v.size();

	sort(v.begin(), v.end()); //sorting the elements of vector in non-decreasing order


	return (long long)v[n-2]*v[n-1]; //returing the product of last 2 numbers of the vector
}

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	cout<<MaxPairwiseProduct_Fast(v);
	return 0;
}
