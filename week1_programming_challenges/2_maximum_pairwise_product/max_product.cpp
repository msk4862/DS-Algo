#include <iostream>
#include <vector>

using namespace std;

int find_max(vector<int>& v) {

	int max = v[0], max_index = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] > max)
		{
			max = v[i];
			max_index = i;
		}
	}
	v.erase(v.begin()+max_index);

	return max;
} 

int find_max_product(vector<int> v) {
	
	int max1 = find_max(v);
	int max2 = find_max(v);

	return max1*max2;
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

	cout<<find_max_product(v);
	return 0;
}