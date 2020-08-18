#include <iostream>
#include <vector>
#include <algorithm> //sort()

using namespace std;

int grouping_fast(vector<float> v) {
	sort(v.begin(), v.end());
	int n = v.size();
	int line = 1, Result[n], k = 0, i =0;

	while(i <= n) {
		line = v[i];		//Start with left hand side
		Result[k++] = line;		
		i += 1;				//Move to next age
		while( i<= n && v[i] <= line+1) 	//insert all ages in line that is in one age differnce
			i +=1;
	}
	
	cout<<"no. of min groups: "<<k;
}

int main() {
	cin>>n;
	vector<float> ages(n);
	for(int i = 0; i< n; ++i) {
		cin>>ages[i];
	}


}