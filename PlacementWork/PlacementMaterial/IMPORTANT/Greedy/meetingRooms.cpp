//https://www.lintcode.com/problem/meeting-rooms-ii/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

bool comp(pair<int, int> meeting1, pair<int, int> meeting2) {
	return meeting1.second < meeting2.second;
}

int getRooms(vector<pair<int, int>> meetings) {
	sort(meetings.begin(), meetings.end(), comp);
	int prev = 0, next = 1;

	int n = meetings.size();
	int plat_count = 1, result = 0;
	while(prev < n && next < n) {
		// overlap
		if(meetings[prev].second >= meetings[next].first) {	
			plat_count++;
			next++;
		}
		// one meeting is over
		else if(meetings[prev].second < meetings[next].first) {	
			plat_count--;
			prev++;
		}
		
		result = max(result, plat_count);
	}

	return result;
}

void solve() {   
	int n;
	cin>>n;
	// start, end
	vector<pair<int, int>> meetings;

	for (int i = 0; i < n; ++i) {
		int start, end;
		cin>>start>>end;
		meetings.push_back({start, end});
	}


}

int main() {
    FASTIO
    solve();
    return 0;
}