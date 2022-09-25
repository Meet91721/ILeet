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
    
    int cnt = 0;
    
    int dfs(TreeNode* node){
        if(node == NULL)
            return 0;
        int res = 1;
        int t1 = 0, t2 = 0;
        if(node->left!=NULL){
            if(node->left->val == node->val){
                t1 = dfs(node->left)+1;
            }
            else{
                int t = dfs(node->left);
                cnt = max(t,cnt);
            }
        }
        if(node->right!=NULL){
            if(node->right->val==node->val){
                t2 = max(dfs(node->right)+1,res);
            }
            else{
                int t = dfs(node->right);
                cnt = max(t,cnt);
            }
        }
        res+=max(t1,t2);
        cnt = max(cnt,t1+t2+1);
        return res;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int t = dfs(root);
        return max(max(cnt-1,t-1),0)/2;
    }
};