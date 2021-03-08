class Solution {
public:
    int countLessNums(vector<int>& nums1, vector<int>& nums2, int val) {
        /*
            Returns values that are equal or smaller than val
        */

        int count  =0;

        //O(log(m))
        count += upper_bound(nums1.begin(), nums1.end(), val) - nums1.begin();
        //O(log(n))
        count += upper_bound(nums2.begin(), nums2.end(), val) - nums2.begin();

        return count;
    }

    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int minV, maxV;

        if(n1 > 0 && n2 > 0) {
            minV = min(nums1[0], nums2[0]);
            maxV = max(nums1[n1-1], nums2[n2-1]);
        }
        // if any of the array is empty
        else if(n1 > 0) {
            minV = nums1[0];
            maxV = nums1[n1-1];
        }
        else {
            minV = nums2[0];
            maxV = nums2[n2-1];
        }


        // value of maxV in worst case will 2^32 - 1 => log(2^32) = 32
        while(minV <= maxV) {
            int mid = (maxV-minV)/2 + minV;

            //O(log(n)) + O(logm)
            int count = countLessNums(nums1, nums2, mid);
            if(count < k) minV = mid+1;
            else maxV = mid-1;
        }

        return minV;
    }

    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // using kth element of two sorted arrays problem
        /*
        Optimisation 3:
        Using binary search (like matrixMedian problem)
        Time: O(32*(logn + logm)), Space: O(1)
        */
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        int med = (n1+n2)/2;
        if((n1 + n2)%2 != 0) {
            return kthElement(nums1, nums2, med+1);        
        }
        
        int med1 = kthElement(nums1, nums2, med+1);        
        int med2 = kthElement(nums1, nums2, med);        

        return (med1+med2)/2.0;
    }
};
