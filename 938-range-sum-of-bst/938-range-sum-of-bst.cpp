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
    
    int res = 0;
    
    void traversal(TreeNode * node, int high, int low){
        if(node == NULL){
            return;
        }
        if(node->val <= high && node->val >= low){
            res+=node->val;
        }
        traversal(node->left, high, low);
        traversal(node->right, high, low);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        traversal(root, high, low);
        return res;
    }
};