#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;;

int start_binary_search(vector<int> &starts, int point, int left, int right) {
	int count = 0;
	while(left <= right) {
		int mid = left + (right - left)/2;

		if (starts[mid] > point)
		{
			right = mid -1;
		}
		else if (starts[mid] <= point)
		{
			if (mid==right || starts[mid+1] > point)
			{
				count += mid +1;
				break;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return count;
}

int end_binary_search(vector<int> &ends, int point, int left, int right) {
	int count = 0;
	while(left <= right) {
		int mid = left + (right - left)/2;

		if (ends[mid] < point)
		{
			left = mid +1;
		}
		else if (ends[mid] >= point)
		{
			if (mid==left || ends[mid-1] < point)
			{
				count += (ends.size() - mid);
				break;
			}
			else {
				right = mid - 1;
			}
		}
	}
	return count;
}


//total segments = segmen with <=x  + segement having x +  segmen with >=x
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  
  std :: sort(starts.begin(), starts.end());
  std :: sort(ends.begin(), ends.end());

  vector<int> start_point(points.size());
  vector<int> end_point(points.size());

  for (int i = 0; i < points.size(); ++i)
  {
  	start_point[i] = start_binary_search(starts, points[i], 0, starts.size()-1);
  	end_point[i] = end_binary_search(ends, points[i], 0, ends.size()-1);

  }

  int total_segments = starts.size();
  for (int i = 0; i < points.size(); ++i)
  {
  	cnt[i] = start_point[i] + end_point[i] - total_segments;
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> starts(n); 
  vector<int> ends(n);
  vector<int> points(m);

  for (int i = 0; i < n; i++) {
    cin >> starts[i] >> ends[i];
  }
  
  for (int i = 0; i < m; i++) {
    cin >> points[i];
  }

  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
