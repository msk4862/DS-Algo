class KthLargest {
public:
    // stream = [9,2,5,7,10], K=3
    // We will store largest K elements in min heap by removing smaller ones (that's why min heap because max heap will just give maximum val)
    // At the end we will have [7,9,10] elements in our heap which is
    // largest K elements in sorted array  [2,5,7,9,10]
    // and we just need the minimum of those K elements
    
    priority_queue<int, vector<int>, greater<int>> min_hp;
    int K;
    
    // check if new val is among largest K elements 
    void updateHeap(int val) {
        if(min_hp.size() < K) min_hp.push(val);
        else if(min_hp.top() < val) {
            min_hp.pop();
            min_hp.push(val);
        }
    }
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int e: nums) {
            updateHeap(e);
        }
    }
    
    int add(int val) {
        updateHeap(val);
        return min_hp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
