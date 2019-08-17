#include <iostream>

int get_change(int m) {
  int coins = 0;
  int tens = 0, fives = 0, ones = 0;

  tens = m/10;
  m %= 10;

  fives = m/5;
  m %= 5;

  ones = m;
  return tens+fives+ones;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
