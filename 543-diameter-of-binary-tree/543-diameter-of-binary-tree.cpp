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
    
    int depth(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int d1 = depth(node->left);
        int d2 = depth(node->right);
        if(d1 + d2 > res){
            res = d1 + d2;
        }
        return max(d1,d2) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return res;
    }
};