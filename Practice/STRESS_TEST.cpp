#include<iostream>
using namespace std;

#define ll long long int

int main()
{
	const ll number_min = 0;
	const ll number_max = 1000000000;

	const ll array_size_min = 1;
	const ll array_size_max = 1000;


	while(true) {
		srand(time(NULL));

		int array_size = rand() % array_size_max + array_size_min;
		
		vector<ll> v(n);
		for (int i = 0; i < n; ++i)
		{
			v[i] = rand() % number_max + number_min;
		}

		for (int i = 0; i < n; ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<"\n";

		long long res1 = NAIVE_SOLUTION(v);
		long long res2 = FASTER_SOLUTION(v);

		if (res1 == res2)
		{
			cout<<"OK\n";
		}
		
		else {
			cout<<"Wrong Answer "<<res1<<" "<<res2<<endl;
			break;
		}

	}

	return 0;
}