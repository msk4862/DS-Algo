#include<iostream>
#include<vector>

using namespace std;

int findPeak(vector< vector<int> > a) {

    int l = 0, r = a[0].size()-1;
    while (l <= r) {

        int mid = (l+r)/2;

        int oneDpeak = a[0][mid], oneDpeakI;

        // finding global maximum in mid col
        for (int i = 1; i < a.size(); i++) {
            if(a[i][mid] > oneDpeak) {
                oneDpeak = a[i][mid];
                oneDpeakI = i;
            }
        }
        
        if (mid == 0) {

            return a[oneDpeakI][mid];

        } else if (mid == a.size()-1) {

            return a[oneDpeakI][mid];

        }
           

        if(a[oneDpeakI][mid] >= a[oneDpeakI][mid-1] && a[oneDpeakI][mid] >= a[oneDpeakI][mid+1]) {

            return a[oneDpeakI][mid];

        } else if (a[oneDpeakI][mid] <= a[oneDpeakI][mid-1]) {

            r = mid-1;

        } else {

            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int rows, cols;
    cin>>rows>>cols;

    vector<vector <int> > ar(rows, vector<int> (cols));
    
    for (int i = 0; i < rows; i++)
    {   
        for (int j = 0; j < cols; j++) {
            cin>>ar[i][j];
        }
    }
    cout<<findPeak(ar);

    return 0;

}
