#include<iostream>
using namespace std;

int smallestMult(int n) {
    
    long num = 2*n;
    bool divisible = true;
    while(true) {
        divisible = true;
        for (int i = 2; i <= n; i++)
        {
            if(num%i != 0) {
                divisible = false;
                break;
            }
        }
        if(divisible) 
            return num;
        else
            num += n;
    }
    
    
}

int main() {    
    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<smallestMult(n);
    return 0;

}
