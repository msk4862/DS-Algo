#include<iostream>
#include<algorithm>

using namespace std;

void laxicalOrder(int nums[], long long int n) {

    long long int k =0;
    int size = 10;

    while (k< n)
    {
        
        int largestX = -1, largestY;
        
        //find largest x for which p[x] < p[x+1]
        for (int i = 0; i < size-1; ++i) {
            if(nums[i] < nums[i+1]) {
                largestX = i;
            }
        }

        if (largestX ==-1)
        {
            break;
        }
        
        //find largest y for which p[x] < p[y]
        for (int i = 0; i < size; ++i) {
            if(nums[largestX] < nums[i]) {
                largestY = i;
            }
        }

        // swap(nums[largestX], nums[largestY]);
        int temp = nums[largestX];
        nums[largestX] = nums[largestY];
        nums[largestY] = temp;

        reverse(nums+largestX+1, nums+size);

        // for (int i = 0; i < size; ++i) {
        //     cout<<nums[i]<< " ";
        // }
        // cout<<endl;

        k++;
    }
    
    for (int i = 0; i < size; ++i) {
            cout<<nums[i];
    }
}

int main() {    
    
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    long long int n;
    cin>>n;
    laxicalOrder(nums, n);
    return 0;

}
