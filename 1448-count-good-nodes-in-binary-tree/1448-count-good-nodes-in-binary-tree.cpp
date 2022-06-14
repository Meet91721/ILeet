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
    void recurse(TreeNode* node, int mx){
        if(node == NULL)
            return;
        if(node->val >= mx)
        {
            // cout << node->val << '\n';
            cnt++;
            recurse(node->left,node->val);
            recurse(node->right,node->val);
            return;
        }
        recurse(node->left,mx);
        recurse(node->right,mx);
    }
    
    int goodNodes(TreeNode* root) {
        recurse(root, INT_MIN);
        return cnt;
    }
};