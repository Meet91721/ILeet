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
    
    int res = INT_MIN;
    
    int dfs(TreeNode* node){
        if(node == NULL)
            return 0;
        int cnt = node->val;
        int t1 = dfs(node->left);
        int t2 = dfs(node->right);
        res = max(res,cnt+t1+t2);
        res = max(res,cnt + max({t1,t2,0}));
        return cnt + max({t1,t2,0});
    }
    
    int maxPathSum(TreeNode* root) {
        return max(res,dfs(root));
    }
};