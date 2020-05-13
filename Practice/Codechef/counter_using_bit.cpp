#include<iostream>
using namespace std;

const int N = 7, bits = 8;

bool is_bit_on (int x, int pos) {
    return (x & (1<<pos)) != 0;
}

void flip_bit(int &x, int pos) {
    x ^= (1<<pos);
}

void increament(int &x) {
    for (int i = 0; i < bits; i++) {
        if(is_bit_on(x, i)) {
            flip_bit(x, i);
        } else {
            flip_bit(x, i);
            break;
        }
    }
}

int main () {
    int counter = 0;
    for(int i = 0; i < N; ++i) {
        increament(counter);
        cout<<counter<<", ";
    }

}