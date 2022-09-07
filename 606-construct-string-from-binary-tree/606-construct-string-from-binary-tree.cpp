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
    
    string res;
    
    void dfs(TreeNode* node){
        if(node==NULL)
            return;
        res+=to_string(node->val);

        if(node->left == NULL && node->right == NULL)
            return;
        res+='(';
        dfs(node->left);
        res+=')';
        if(node->right == NULL)
            return;
        res+='(';
        dfs(node->right);
        res+=')';
    }
    
    string tree2str(TreeNode* root) {
        dfs(root);
        return res;
    }
};