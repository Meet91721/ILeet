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
    
    int moves = 0;
    
    int dfsTraversal(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        
        int l = dfsTraversal(node->left);
        int r = dfsTraversal(node->right);
        
        moves += abs(l) + abs(r);
        
        return node->val + l + r - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        dfsTraversal(root);
        return moves;
    }
};