/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree = "";
        
        if(!root) return tree;
        
        queue<TreeNode*> q;
        q.push(root);
        tree += to_string(root->val) + " ";
        
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            
            if(cur->left == nullptr) tree += "null ";
            else {
                q.push(cur->left);
                tree += to_string(cur->left->val) + " ";
            }
            
            if(cur->right == nullptr) tree += "null ";
            else {
                q.push(cur->right);
                tree += to_string(cur->right->val) + " ";
            }
        }
        return tree;
    }

    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        
        string rootEl = string(strtok((char*)data.c_str(), " "));

        TreeNode* root = new TreeNode(stoi(rootEl));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            string leftEl = string(strtok(NULL, " "));
            string rightEl = string(strtok(NULL, " "));
            
            TreeNode* cur = q.front();
            q.pop();
            
            // cout<<leftEl<<rightEl;
            if(leftEl.compare("null") == 0) cur->left = nullptr;
            else {
                TreeNode* left = new TreeNode(stoi(leftEl));
                cur->left = left;
                q.push(left);
            }
            if(rightEl.compare("null") == 0) cur->right = nullptr;
            else {
                TreeNode* right = new TreeNode(stoi(rightEl));
                cur->right = right;
                q.push(right);
            }

        }
        
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
