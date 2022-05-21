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
    
    bool dfs(TreeNode* node, int sum, int target){
        if(node == NULL){
            // if(target == sum)
            //     return true;
            return false;
        }
        if(node->left == NULL && node ->right == NULL){
            if(sum + node->val == target){
                return true;
            }
            return false;
        }
        
        return dfs(node->left, sum+(node->val), target) || dfs(node->right, sum+(node->val), target);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return dfs(root, 0, targetSum);
    }
};