#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

bool isMajority(vector<int> &a, int major_el) {
  int count = 0;
 for (int i = 0; i < a.size(); ++i)
  {
    if (a[i] == a[major_el])
    {
      count++;
    }
  } 

  if (count > a.size()/2)
    return true;
  else 
    return false;
}

//
bool get_majority_element_fast(vector<int> &a) {
  int major_el = 0, count =1;
  for (int i = 1; i < a.size(); ++i)
  {
    if (a[major_el] == a[i])
    {
      count++;
    }
    else {
      count--;
    }
    if (count == 0)
    {
      count =1;
      major_el = i;
    }
  }

  return isMajority(a, major_el);
}

int get_majority_element1(vector<int> &a) {

  vector<int>::iterator it = max_element(a.begin(), a.end());
  int& ref = (*it);
  int* ptr = &ref;
  vector<int> b((*ptr)+1);

  for (int i = 0; i < b.size(); ++i)
  {
    b[i] = 0;
  }
  for (int i = 0; i < a.size(); ++i)
  {
    b[a[i]]++;
  }

  for (int i = 0; i < b.size(); ++i)
  {
    if (b[i]!= 0 && b[i] > a.size()/2)
    {
      return 1;
    }
  }

  return 0;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element_fast(a) << "\n";

  //std::cout << get_majority_element(a, 0, a.size()) << "\n";

}
