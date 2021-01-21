/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // O(n) space complexity using bfs
    Node* connectHelper(Node* root) {
        queue<Node*> nodes;
        
        nodes.push(root);
        while(!nodes.empty()) {
            queue<Node*> level;
            Node* next = nullptr; 
            while(!nodes.empty()) {
                Node* cur = nodes.front();
                nodes.pop();
                
                cur->next = next;
                next = cur;
                
                // so that right most nodes are popped first
                if(cur->right) level.push(cur->right);
                if(cur->left) level.push(cur->left);
            }
            nodes = level;
        }
        
        return root;
    }
    
    // O(1) space
    Node* connectHelper1(Node* root) {
        Node* level = root;
        
        while(level) {
            
            Node* cur = level;
            // traversing level using next pointer
            while(cur) {
                if(cur->left) cur->left->next = cur->right;
                if(cur->next && cur->right) cur->right->next = cur->next->left;

                cur = cur->next;
            }
            
            level = level->left;
        }
        
        return root;
    }
    
    Node* connect(Node* root) {
        if(!root) return root;
        
        // return connectHelperroot);
        return connectHelper1(root);
        
    }
};
