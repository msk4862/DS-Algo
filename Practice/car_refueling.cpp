#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int refuiling(int d, int m, vector<int> stops) {
	int diff, distanceTravelled = 0;
	int refuils = 0;

	for (int i = 1; i < stops.size(); ++i) {
		diff = stops[i]-stops[i-1];
		// cout<<distanceTravelled<<" "<<diff<<" "<<stops[i]<<endl;
		if ( diff > m) {
			return -1;
		} else {
			if(diff+distanceTravelled<= m) {
				distanceTravelled += diff;
			} else {
				// cout<<"sagajs"<<stops[i];
				refuils += 1;
				distanceTravelled = diff;
			}
		}
	}

	diff = d-stops[stops.size()-1];
		// cout<<distanceTravelled<<" "<<diff<<endl;

	if(diff > m) {
		return -1;
	}
	if(distanceTravelled+diff > m) {
		refuils +=1;
	}

	return refuils;
}

int main() {
	int d, m;
	cin>>d>>m;

	int n;
	cin>>n;
	vector<int> stops(n+1);
	stops[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin>>stops[i];
	}

	cout<<refuiling(d, m, stops);
}