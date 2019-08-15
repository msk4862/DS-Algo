#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
 from = m, to = n
 requied sum = Fm + Fm+1 +...+ Fn = Fn - Fm-1
*/
long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    int l1 = get_fibonacci_huge_fast(from+1, 10);
    int l2 = get_fibonacci_huge_fast(to+2, 10);

    if(l1 <= l2) {
        return l2-l1;
    } else {
        return l2-l1 + 10;
    }


}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
