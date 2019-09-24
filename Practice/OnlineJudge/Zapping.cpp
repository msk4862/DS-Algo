#include<iostream>
#include<vector>

using namespace std;

int main() {
    int a, b;
    cin>>a>>b;
    while (a != -1 && b != -1)
    {
        int min1, min2;
        min1 = abs(a-b);
        if(a <= b) {
           min2 = (a - b + 100); 
        }
        else {
           min2 = (b - a + 100); 
        }

        int min = (min1 >= min2) ? min2 : min1;
        cout<<min<<endl;
        
        cin>>a>>b;
    }
    
}