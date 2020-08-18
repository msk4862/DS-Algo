#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int get_fibonacci_huge_fast(long long n, long long m) {

    long long previous = 0;
    long long current = 1;

    long long pattern[10000], pattern_len = 2;
    pattern[0] = previous;
    pattern[1] = current;

    while(true) {
        long long temp = current;
        current = (current+previous) % m;
        previous = temp;

        if (current == 0) {
            temp = (current + previous) %m;

            if (temp == 1) {
                break;
            }
        }

        pattern[pattern_len++] = current;
    }
    long long rem = n % pattern_len;
    return pattern[rem];
}

/*
sum of fibonacci squares till n = (Fn) * (Fn+1)
 */
long long fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;
    int l1 = get_fibonacci_huge_fast(n, 10);
    int l2 = get_fibonacci_huge_fast(n+1, 10);

    return (l1*l2)%10;
    
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
