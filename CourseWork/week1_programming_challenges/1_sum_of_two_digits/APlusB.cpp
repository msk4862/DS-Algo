#include <iostream>

using namespace std;

int sum(int first_digit, int second_digit) {
    return first_digit + second_digit;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << sum(a, b);
    return 0;
}
