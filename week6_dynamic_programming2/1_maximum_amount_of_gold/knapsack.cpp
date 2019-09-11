#include <iostream>
#include <vector>


using namespace std;

int max(int a, int b) {
  return a>b ? a : b;
}

int dp_knapsack(int W, vector<int> w, vector<int> v, int n) {
  vector< vector<int> > values;

  //matrix of n+1 * W+1
  for (int i = 0; i <= n; ++i)
  {
    values.push_back(vector<int> (W+1));
  }
  int val;

  //items
  for (size_t j = 0; j <= n; j++)
  {

    for (size_t cur_weight = 0; cur_weight <= W; cur_weight++)
    {
      if(cur_weight == 0 || j == 0) {
        values[j][cur_weight] = 0;
      }

      //either include j-1th (becuz indexing in z is from 0) item or not
      else if (cur_weight >= w[j-1])
      {
        values[j][cur_weight] = max(values[j-1][cur_weight - w[j-1]] + v[j-1],
                      values[j-1][cur_weight]);
      }
      else
      {
        values[j][cur_weight] = values[j-1][cur_weight];
      }
      
    }
    
  }

  return values[n][W];
  
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
    v[i] = w[i];
  }
  //here weights are same as value

  std::cout << dp_knapsack(W, w, v, n) << '\n';
}
