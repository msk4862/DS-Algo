#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
  bool visited;

  //operator overloading
  bool operator < (const Segment& seg) const {
    return (end < seg.end);
  }    
};


vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  //sorting in descending order of end points
  sort(segments.begin(), segments.end());
  int currPoint = segments[0].end;
  points.push_back(currPoint);

  for (int i = 0; i < segments.size(); ++i)
  {
    if (segments[i].start > currPoint || segments[i].end < currPoint)
    {
      currPoint = segments[i].end;
      points.push_back(currPoint);
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  for (size_t i = 0; i < segments.size(); ++i) {
    segments[i].visited = false;
  }


  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
