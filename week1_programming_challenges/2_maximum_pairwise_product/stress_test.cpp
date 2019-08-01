#include <iostream>
#include <vector>
#include <algorithm> //sort()
#include <ctime>
#include<cstdlib>
using namespace std;



//fast algo
long long MaxPairwiseProduct_Fast(vector<int> v) {
	
	int n = v.size();

	//sorting in descending order
	sort(v.begin(), v.end()); 


	return (long long)v[n-2]*v[n-1];
}


//Naive algo
long long MaxPairwiseProduct_Naive(const vector<int>& numbers) { 
	long long product = 0;
  	int n = numbers.size();
  	for (int i = 0; i < n; ++i) {
   		for (int j = i + 1; j < n; ++j) {
   			long long temp =(long long) numbers[i] * numbers[j];
   			if (product < temp)
   			{
   				product = temp;
   			}
   		}
    } 
 return product; 
}


int main()
{
	while(true) {
		srand(time(NULL));

		int n = rand() % 10 + 2;
		cout<<n<< "\n";

		vector<int> v(n);

		for (int i = 0; i < n; ++i)
		{
			v[i] = rand() % 10;
		}

		for (int i = 0; i < n; ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<"\n";
		long long res1 = MaxPairwiseProduct_Naive(v);
		long long res2 = MaxPairwiseProduct_Fast(v);

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