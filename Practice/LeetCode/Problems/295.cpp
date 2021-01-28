class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // elements to left of median will be stored in maxHeap
    // and vice versa in maxHeap 
    // left half elements will be in maxHeap
    // right half elements will be in minHeap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()) {
            minHeap.push(num);
            return;
        }
        
        double median = findMedian();        
        if(num < findMedian()) maxHeap.push(num);
        else minHeap.push(num);
        
        // mantaining heaps to be almost equal 
        if(abs(int(minHeap.size()-maxHeap.size())) > 1) {
            if(minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        
        // cout<<" "<<maxHeap.top();
        // even no. of elements
        if(maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top())/2.0;
        
        // median wil shift to right
        if(maxHeap.size() < minHeap.size()) return minHeap.top();
        
        
        // median wil shift to left
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
