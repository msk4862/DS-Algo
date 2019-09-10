#include<iostream>
#include<vector>

using namespace std;

int dp_knapsack(int W, vector<int> w, vector<int> v, int n) {
	vector<int> values(W+1);
	int val;

	for (size_t cur_weight = 0; cur_weight < values.size(); cur_weight++)
	{
		values[cur_weight] = 0;

		for (size_t j = 0; j < n; j++)
		{
			if (cur_weight >= w[j])
			{
				val = values[cur_weight - w[j]] + v[j];
			}
			if (val > values[cur_weight])
			{
				values[cur_weight] = val;
			}
			
		}
		
	}

	return values[W];
	
}

int main() {
	int n, W;
	cin>>W>>n;

	vector<int> w(n);
	vector<int> v(n);
	for (size_t i= 0; i < n; i++)
	{
		cin>>w[i];
	}
	for (size_t  i= 0; i < n; i++)
	{
		cin>>v[i];
	}

	cout<<dp_knapsack(W, w, v, n)<<endl;
}