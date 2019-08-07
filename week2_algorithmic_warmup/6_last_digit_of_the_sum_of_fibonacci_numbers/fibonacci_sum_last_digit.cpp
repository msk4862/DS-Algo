#include <iostream>

using namespace std; 

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current);
        sum += current;
    }

    return sum % 10;
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



//S(n) = F(n+2) – 1

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    unsigned long long num_last_digit = get_fibonacci_huge_fast(n+2, 10);

    if(num_last_digit == 0) {
        return 9;
    }
    else{
       return num_last_digit-1;
    }

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
