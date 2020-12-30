class Solution {
public:
    class Comparator {
        public:
            bool operator()(pair<int, int> a, pair<int, int> b) {
                // min heap
                return a.second > b.second;
            }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // value, frequency
        unordered_map<int, int> freq;
        for(int e: nums) freq[e]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> minHeap;
        
        auto it = freq.begin();
        
        // insert initial k values
        for(int i = 0; i < k; ++i, ++it) {
            minHeap.push(*it);
        }
        
        for(; it != freq.end(); ++it) {
            
            if(minHeap.top().second < it->second) {
                minHeap.push(*it);
                minHeap.pop();
            }
            
        }
        
        vector<int> res;
        while(!minHeap.empty()) {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return res;
    }
};
