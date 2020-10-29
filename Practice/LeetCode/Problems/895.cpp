class FreqStack {
public:
    class Node{
        public:
            int val;
            int freq;
            int index;

            Node(int v, int frq, int ind) {
                val = v;
                freq = frq;
                index = ind;
            }
    };
    
    class comp {
        public:
            bool operator() (Node* n1, Node* n2) {
                if(n1->freq == n2->freq) 
                    return n1->index < n2->index;
                return n1->freq < n2->freq;
            }
    };
    
    unordered_map<int, int> mp;
    priority_queue<Node*, vector<Node*>, comp> st; 
    int index;
    
    FreqStack() {
        index = 0;
    }
    
    void p() {
        for(auto a: mp) {
            cout<<a.first<<":"<<a.second<<" ";
        }
    cout<<st.top()->val<<" "<<st.top()->index<<endl;
    }
    
    void push(int x) {
        int freq = 1;
        if(mp[x]) {
            freq+= mp[x];
            mp[x] = freq;
        }
        else {
            mp[x] = freq;
        }
        // cout<<st.size();
        st.push(new Node(x, freq, index++));
        // p();
    }
    
    int pop() {
        Node* e = st.top();
        mp[e->val]--;
        st.pop();
        return e->val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
