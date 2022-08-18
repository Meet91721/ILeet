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
    
    TreeNode* funcc(TreeNode* root, int limit){
        if(root == NULL)
            return NULL;
        if(root->left == NULL && root->right == NULL){
            if(root->val>=limit)
                return root;
            return NULL;
        }
        
        root->left = funcc(root->left, limit-root->val);
        root->right = funcc(root->right, limit-root->val);
        
        if(root->left == NULL && root->right == NULL)
            return NULL;
        
        return root;
        
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return funcc(root,limit);
    }
};