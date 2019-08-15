#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}



long gcd_fast(int a, int b) {
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

long long int lcm_fast(int a, int b) {

  long gcd = gcd_fast(a, b);
	long long int lcm = ((long long int)(a/gcd)*b);

	return lcm;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
