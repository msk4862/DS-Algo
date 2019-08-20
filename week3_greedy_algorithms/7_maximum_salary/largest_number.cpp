#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <csstream>

using namespace std;

bool is_max(string n1, string maxDigit) {

  if (maxDigit.length() == n1.length())
    return stoi(maxDigit) < stoi(n1);
  
  else {
  int a1 = std::stoi(n1.append(maxDigit));
  int a2 = std::stoi(maxDigit.append(n1));

  if (a1 > a2)
  {
    return true;
  }
  else {
    return false;
  }
}
}


string largest_number(vector<string> a) {
  //write your code here

  string maxDigit = "0", result = "";
  int maxDigitIndex = 0;

  while(a.size() > 0) {
    for (int i = 0; i < a.size(); ++i)
    { 
      if (is_max(a[i], maxDigit))
      {
        maxDigit = a[i];
        maxDigitIndex = i;
      }
    }
    a.erase (a.begin()+maxDigitIndex);
    result.append(maxDigit);
  }

  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
