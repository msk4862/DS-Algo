#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(pair<ll, ll> p1, pair<ll, ll> p2) {
	
	double v1 = (double) p1.first/p1.second;
	double v2 = (double) p2.first/p2.second;
	
	return v1 > v2;
}

double max_loot(ll n, ll W, pair<ll, ll> items[]) {
	double value = 0; 
	ll spaceLeft=W;

	//sorting items based on value per unit item 
	sort(items, items + n, compare);

	for (int i = 0; i < n && spaceLeft > 0; ++i) {
		ll v = items[i].first;
		ll w = items[i].second;
		if(w <= spaceLeft) {
			value += v;
			spaceLeft -= w;
		} else {
			value += (double) (v*spaceLeft)/w;
			spaceLeft = 0;
		}
	}

	return value;
	
}

int main() {
	ll n, W;
	cin>>n>>W;

	pair<ll, ll> items[n];
	for (int i = 0; i < n; ++i) {	
		ll v, w;
		cin>>v>>w;
		items[i].first = v;
		items[i].second = w;
	}

	cout<<fixed<<setprecision(4)<<max_loot(n, W, items);
}