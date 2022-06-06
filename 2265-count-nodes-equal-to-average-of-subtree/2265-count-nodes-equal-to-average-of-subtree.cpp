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
    
    pair<int,int> traversal(TreeNode* node){
        if(node == NULL)
            return {0,0};
        
        auto [v1,n1] = traversal(node->left);
        auto [v2,n2] = traversal(node->right);
        
        int val = v1+v2+node->val;
        int n = n1+n2+1;
        if(node->val == val/n)
            res++;
        return {val,n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        traversal(root);
        return res;
    }
};