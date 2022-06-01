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
    
    TreeNode* traversal(TreeNode* actual){
        if(actual == NULL)
            return NULL;
        TreeNode* node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val = actual->val;
        node->left = traversal(actual->right);
        node->right = traversal(actual->left);
        return node;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* r = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if(root == NULL)
            return root;
        r->val = root->val;
        r->left = traversal(root->right);
        r->right = traversal(root->left);
        return r;
    }
};