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
    
    TreeNode* res=NULL;
    
    bool funcc(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL)
            return false;
        
        bool left = funcc(node->left,p,q);
        bool right = funcc(node->right,p,q);
        
        if(left && right){
            res=node;
            return false;
        }
        
        if(left || right){
            if(node == p || node == q)
            {
                res = node;
                return false;
            }
            return true;
        }
        
        return (node == p) || (node == q);
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        funcc(root,p,q);
        return res;
    }
};