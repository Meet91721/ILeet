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
    
    bool func(TreeNode* node){
        if(node == NULL)
            return false;
        bool found = (node->val == 1);
        if(func(node->left)==false)
            node->left = NULL;
        else
            found = 1;
        if(func(node->right)==false)
            node->right = NULL;
        else
            found = 1;
        return found;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(func(root)==false)
            return NULL;
        return root;
    }
};