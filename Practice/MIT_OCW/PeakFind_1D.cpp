#include<iostream>
#include<vector>

using namespace std;

int findPeak(vector<int> a) {

    int l = 0, r = a.size()-1;
    while (l <= r)
    {
        int mid = (l+r)/2;

        if (mid == 0) {
            if (a[mid] > a[mid+1]) {
                return a[mid];
            }   
        } else if (mid == a.size()-1) {
            if (a[mid] > a[mid-1]) {
                return a[mid];
            }
        }
           

        if(a[mid] > a[mid-1] && a[mid] > a[mid+1]) {
            return a[mid];
        } else if (a[mid] < a[mid-1]) {
            r = mid-1;
        } else {
            l = mid + 1;
        }
        
    }
    

    return -1;
}

int main() {
    int n;
    cin>>n;

    vector<int> ar;
    
    int e;

    for (int i = 0; i < n; i++)
    {   
        cin>>e;
        ar.push_back(e);
    }
    
    cout<<findPeak(ar);

    return 0;

}
