#include <iostream>
#include <vector>
#include <numeric>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  int i = 1;
  int rem_sum = n;

  while(rem_sum > 2*i) {
      rem_sum -= i;
      summands.push_back(i);
      i++;
  }
  
  // if sum is not yet completed
  if (accumulate(summands.begin(), summands.end(), 0) < n)     // for sum 
  {
      summands.push_back(rem_sum);
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
