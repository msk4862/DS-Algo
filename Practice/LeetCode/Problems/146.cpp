class LRUCache {
public:
    /* 
        Approach 1: Can use an array
        0th index = MRU, last index = LRU
        get: search the whole array for key 
            if found -> shift values before it to forward and put it to first 
            if not found -> return -1
        put: search array 
            if already present ->shift values before it to forward and put it to first index
            if not(size full)->remove last ind(LRU) shift values to forward and insert at first
            if not(size not full)->insert at first    
        time: get, put: O(n(searching) + n(shifting)), Space: O(n)
    */
    
    /* 
        Optimisation 1: can use hash map to reduce time for searching
    */
    
    /* 
        Optimisation 2: can use linked lsit to reduce time for shifting
        Time: O(1)
    */
    
    
    // key -> value
    list<pair<int, int>> cache;

    // key -> address
    unordered_map<int, list<pair<int, int>>::iterator> address;
    int capacity;

    // move accessed element to front (MRU)
    void refreshCache(int key, int value) {
        cache.erase(address[key]);
        cache.push_front(make_pair(key, value));

        address[key] = cache.begin();
    }

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }
    
        int get(int key) {
            if(address.count(key) == 0) return -1;

            refreshCache(key, (*address[key]).second);
            return (*address[key]).second;
        }
        
        void put(int key, int value) {
            // already present
            if(address.count(key) > 0) {
                refreshCache(key, value);
                return;
            }

            // add to cache
            cache.push_front(make_pair(key, value));
            address[key] = cache.begin();   

            if(cache.size() > capacity) {
                // cache is full 
                // page replacement occurs      
                // remove least reacently used
                address.erase(cache.back().first);
                cache.pop_back();

            }
        }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
