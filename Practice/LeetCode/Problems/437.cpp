/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    /* Hash map approach
    void calcSum(TreeNode* root, int sum, int &count, unordered_map<int, int> mp = {}, int cumulativeSum = 0) {
        if(!root) return;

        cumulativeSum += root->val;

        // one extra 
        if(cumulativeSum == sum) count++;
        
        // found one
        if(mp.find(cumulativeSum-sum) != mp.end())  {
            count+=mp[cumulativeSum-sum];
            // mp[cumulativeSum-sum] += 1;
        }
        mp[cumulativeSum] += 1;
        
        calcSum(root->left, sum, count, mp, cumulativeSum);
        calcSum(root->right, sum, count, mp, cumulativeSum);
    }
    */
    
    int getCount(TreeNode* root, int sum) {
        if(!root) return 0;
        
        int count = root->val == sum ? 1 : 0;
        count += getCount(root->left, sum-root->val);
        count += getCount(root->right, sum-root->val);
        
        return count;
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        return getCount(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        
        /*        
        int res = 0;
        calcSum(root, sum, res);
        
        return res;
        */
    }
};
