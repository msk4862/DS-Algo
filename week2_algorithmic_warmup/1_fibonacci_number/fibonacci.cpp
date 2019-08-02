#include <iostream>
#include <cassert>

using namespace std;
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    int a[n+1];

    a[0] = 0;
    a[1] = 1;

    for (int i = 2; i < (n+1); ++i) {
        a[i] = a[i-1] + a[i-2];
    }

    return a[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    cin >> n;

    //cout << fibonacci_naive(n) << '\n';
    test_solution();
    //cout << fibonacci_fast(n) << '\n';
    return 0;
}
