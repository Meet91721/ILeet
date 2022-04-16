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
    
    int funcc(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        return max(funcc(node->left), funcc(node->right)) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return funcc(root);
    }
};