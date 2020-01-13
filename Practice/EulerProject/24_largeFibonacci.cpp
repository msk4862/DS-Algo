#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int nDigitFibo(int n) {

    vector<int> cur(1, 1);
    int fiboIndex = 1;

    vector<int> prev(1, 0);
    vector<int> temp;

    int res= 0;

    while (cur.size() != n)
    {
        int carry = 0;
    
        temp = cur;
        for (int i = 0; i < cur.size(); i++)
        {
            if(i < prev.size()) {
                res = carry + prev[i] + cur[i];
            }
            else {
                res = carry + cur[i];
            }

            cur[i] = res%10;
            carry = res/10;
        }
        
        
        while (carry > 0)
        {
            cur.push_back(carry%10);
            carry/=10;
        }
        //correcting ordering of numbers
        // reverse(cur.begin(), cur.end());
        prev = temp;

        for (int i = 0; i < cur.size(); ++i) {
            cout<<cur[i]<<" ";
        }
        cout<<endl;
        
        fiboIndex++;
    }
    
    return fiboIndex;
}

int main() {    
    
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n;
    cin>>n;
    cout<<nDigitFibo(n);
    return 0;

}
