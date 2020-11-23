#include<bits/stdc++.h>
using namespace std;

// https://massivealgorithms.blogspot.com/2019/12/leetcode-1256-encode-number.html
int main()
{
    int num;
    cin>>num;
    
    // find length
    // block size is 1, 2, 4, 8, ... of pattern 
    int length = 0;
    int tempN = num;
    while(tempN - pow(2, length) > 0) {
        tempN-=pow(2, length);
        length++;
    }        

    cout<<length<<" ";

    // find the encoded string
    // by finding index of that block = num - size of block+1
    string res = "";
    int blockInd = num - pow(2, length) +1;
    cout<<blockInd<<" ";
    for (int i = 0; i < length; ++i) {
        res = to_string((blockInd>>i) & 1) + res;
    }

    cout<<res;

    
    return 0;
}