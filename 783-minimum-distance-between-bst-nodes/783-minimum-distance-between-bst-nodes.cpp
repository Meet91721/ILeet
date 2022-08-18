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
    
    int ans = INT_MAX;
    
    pair<int,int> funcc(TreeNode* node){
        int mn = node->val, mx = node->val;
        if(node->left != NULL){
            auto [a,b] = funcc(node->left);
            mn = min(mn,a);
            mx = max(mx,b);
            ans = min({ans,abs(a-node->val),abs(b-node->val)});
        }
        if(node->right !=NULL){
            auto [a,b] = funcc(node->right);
            mn = min(mn,a);
            mx = max(mx,b);
            ans = min({ans,abs(a-node->val),abs(b-node->val)});
        }
        return {mn,mx};
    }
    
    int minDiffInBST(TreeNode* root) {
        funcc(root);
        return ans;
    }
};