#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


int gcd_fast(int a, int b) {
  while(a != 0 && b != 0) {
    if(a<b) {
      b %= a;
    }
    else {
      a %= b;
    }
  }

  int gcd = (a==0)? b : a;

  return gcd;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
