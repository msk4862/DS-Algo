class Solution {
public:
    void swap(vector<int>& n, int i, int f) {
        int t = n[i];
        n[i] = n[f];
        n[f] = t;
    }
    
    // using quick select
    int findKth(vector<int>& n, int s, int l, int k) {
        if(l >= n.size()) return -1;
        int pivot = n[l];
        
        int small = s;
        // partition
        for(int i = s; i < l; ++i) {
            if(n[i] >= pivot) {
                swap(n, i, small);
                small++;
            }
        }
        
        // put pivot
        swap(n, l, small);
        
        if(k-1 == small) return n[small];
        //left half
        if(k-1 < small+1) return findKth(n, s, small-1, k);
        // right half
        return findKth(n, small+1, l, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // return findKth(nums, 0, nums.size()-1, k);
        
        //IMP -> // another approach can be priority queue using MIN heap
        priority_queue<int, vector<int>, greater<int>> largest(nums.begin(), nums.begin()+k);
        for(int i = k; i < nums.size(); ++i) {
            if(largest.top() < nums[i]) {
                largest.pop();
                largest.push(nums[i]);
            }    
        }

        return largest.top();

    }
};
