/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flat;
    int cur;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        cur = 0;
    }

    void flatten(vector<NestedInteger> l) {
        if(l.size() == 0) return;
        
        for(int  i = 0; i < l.size(); ++i) {
            if(l[i].isInteger()) flat.push_back(l[i].getInteger());
            else flatten(l[i].getList());
        }
    }
    
    
    int next() {
        return flat[cur++];
    }
    
    bool hasNext() {
        return cur < flat.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */