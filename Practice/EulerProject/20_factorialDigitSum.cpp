#include<iostream>
#include<vector>

using namespace std;

void multiply(vector<int> &v, int n) {
    int carry = 0;
    int res ;
    
    for (int i = 0; i < v.size(); i++)
    {
        res = carry + v[i]*n;
        v[i] = res%10;
        carry = res/10;
    }

    while (carry > 0)
    {
        v.push_back(carry%10);
        carry/= 10;
    }  
}

int digitSum(int n) {
    
    vector<int> v;
    v.push_back(1); 

    for(int i = 2; i <= n; ++i) {
        multiply(v, i);
    }

    int sum = 0;
    for(int i = v.size()-1; i >= 0; --i) {
                sum+=v[i];
    }    
    return sum;
}

int main() {    
    int n;
    cout<<"Enter no.";
    cin>>n;
    cout<<digitSum(n);
    return 0;

}
