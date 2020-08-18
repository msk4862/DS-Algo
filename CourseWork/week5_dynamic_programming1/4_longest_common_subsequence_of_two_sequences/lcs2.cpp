#include <iostream>
#include <vector>
//#include <unordered_map> 

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
    

  int n = a.size()+1;
  int m = b.size()+1;
  int distance[n][m];

  for (int i = 0; i < n; ++i)
  {
    distance[i][0] = 0;
  }
  for (int i = 0; i < m; ++i)
  {
    distance[0][i] = 0;
  }

  int insert, del, match;
  for (int j = 1; j < m; ++j)
  {
    for (int i = 1; i < n; ++i)
    { 
      //inserting a space in second string
      insert = distance[i][j-1];
      //inserting a space in first string
      del = distance[i-1][j];

      match = distance[i-1][j-1]; 

      //one more commmon element
      if (a[i-1] == b[j-1])
      {
        distance[i][j] = distance[i-1][j-1] + 1;
      }
      else {
        distance[i][j] = (insert > del) ? ((insert > match) ? insert : match) : 
                                  ((del > match) ? del : match);
      }
    }
  }

  return distance[n-1][m-1];
}


int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }


  std::cout << lcs2(a, b) << std::endl;
}
