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
    
    int sum(int depth, TreeNode* node){
        if(node == NULL){
            return 0;
        }
        if(depth == 2){
            return node->val;
        }
        return sum(depth + 1, node->left) + sum(depth + 1, node->right);
    }
    
    void traversal(TreeNode* node){
        if(node == NULL){
            return;
        }
        if(node->val % 2 == 0){
            res += sum(0, node);
        }
        
        traversal(node->left);
        traversal(node->right);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        traversal(root);
        return res;
    }
};