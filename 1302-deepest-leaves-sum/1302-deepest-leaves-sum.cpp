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
    
    int maxDepth(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        return max(maxDepth(node->left), maxDepth(node->right)) + 1;
    }
    
    int funcc(int maxD, TreeNode* node, int currD){
        if(node == NULL){
            return 0;
        }
        if(maxD == currD){
            return node->val;
        }
        return funcc(maxD, node->left, currD + 1) + funcc(maxD, node->right, currD + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int depth = maxDepth(root);
        return funcc(depth, root, 1);
    }
};