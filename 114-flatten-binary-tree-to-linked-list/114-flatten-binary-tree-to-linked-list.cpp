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
    
    void funcc(TreeNode* node, TreeNode* &root){
        
        if(node == NULL)
            return;
        
        // cout << node->val << " " << root->val << '\n';
        root->right=new TreeNode(node->val);
        root = root->right;
        funcc(node->left,root);
        funcc(node->right,root);
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left=NULL;
        root->right=NULL;
        funcc(left,root);
        funcc(right,root);
    }
};