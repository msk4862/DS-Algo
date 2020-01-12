#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

int sumDivisors(int n) {

    int sum = 1;
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            sum+=i;
            if(n/i != i) {
                sum+=n/i;
            }
        }
        
    }

    return sum;
}

int sumAmicableNum(int n) {

    vector<int> divisorsSum(n, 0);
    int sum=0;
    
    for (int i = 2; i < n; i++)
    {   
        divisorsSum[i] = sumDivisors(i);

        if(divisorsSum[i] < n && divisorsSum[divisorsSum[i]] == i && i != divisorsSum[i]) {
            sum += i+divisorsSum[i];
            divisorsSum[i] = 0;
        }
    }

    return sum;
}

int main() {    
    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<sumAmicableNum(n);
    return 0;

}
