class MyHashSet {
public:
    /** Initialize your data structure here. */
    int N;
    vector<vector<int>> hash;
    MyHashSet() {
        N = 15000;
        hash = vector<vector<int>>(N);
    }
    
//     using separate chaining
    void add(int key) {
        int pos = key%N;   
        if(find(hash[pos].begin(), hash[pos].end(), key) == hash[pos].end()) {
            hash[pos].push_back(key);
        }
    }
    
    void remove(int key) {
        int pos = key%N;   
        vector<int>::iterator it = find(hash[pos].begin(), hash[pos].end(), key);
        if(it != hash[pos].end()) {
            hash[pos].erase(it);
            return;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = key%N;   
        if(find(hash[pos].begin(), hash[pos].end(), key) != hash[pos].end()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
