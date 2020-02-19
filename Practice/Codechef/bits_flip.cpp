#include<bits/stdc++.h>

using namespace std;

// maximizing ar 
vector<int> flip(string A) {
    int cur_max = 0, max_now = INT32_MIN;

    vector<int> ar(A.size());
    vector<int> res(2);
    int start = 0;

    for (int i = 0; i < A.length(); i++)
    {
        if(A[i] == '0') 
            ar[i] = 1;
        else
            ar[i] = -1;
    }
    

    for(int i = 0; i < A.length(); ++i) {
        cur_max += ar[i];

        
        if (max_now < cur_max && cur_max >= 0)
        {   
            max_now = cur_max;
            res[0] = start+1;
            res[1] = i+1;
        }

        if(cur_max < 0) {
            cur_max = 0;
            start = i+1;
        }

        
    }
    if(res[0] == 0) {
        res = {};
    }
    return res;

}
