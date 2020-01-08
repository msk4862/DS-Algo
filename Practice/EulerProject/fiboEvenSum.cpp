#include<iostream>
using namespace std;


int fiboEvenSum(int n) {
    int prev = 0;
    int cur = 1;

    long sum = 0;
    while (n--) {
        int temp = cur;
        cur = prev+cur;
        prev = temp;

        if(cur%2==0) {
            sum+=cur;
        }
    }

    return sum;

}

int main() {
    cout<<fiboEvenSum( 43);
    return 0;

}
