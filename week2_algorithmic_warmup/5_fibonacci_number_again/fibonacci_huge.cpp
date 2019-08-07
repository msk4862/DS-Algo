#include <iostream>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {

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

    for (int i = 0; i < pattern_len; ++i)
    {
        cout<<pattern[i];    
    }
    cout<<endl;
    long long rem = n % pattern_len;
    return pattern[rem];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
