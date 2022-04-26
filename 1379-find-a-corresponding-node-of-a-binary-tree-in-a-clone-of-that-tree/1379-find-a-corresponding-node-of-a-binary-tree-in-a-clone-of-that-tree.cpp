/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* funcc(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original == target){
            return cloned;
        }
        if(original == NULL){
            return NULL;
        }
        if(funcc(original->right, cloned->right, target) == NULL){
            return funcc(original->left, cloned->left, target);
        }
        return funcc(original->right, cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return funcc(original, cloned, target);
    }
};