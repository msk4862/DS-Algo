/*
   LRU Cache
   
*/

class LRUCache {
public:
    
    // key -> value
    list<pair<int, int>> cache;

    // key -> address
    unordered_map<int, list<pair<int, int>>::iterator> address;
    int capacity;

    // move accessed element to front
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