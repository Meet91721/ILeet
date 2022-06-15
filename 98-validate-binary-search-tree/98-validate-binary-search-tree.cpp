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
    
    vector<int>s;
    
    void recurse(TreeNode* node){
        if(node == NULL)
            return;
        recurse(node->left);
        s.emplace_back(node->val);
        recurse(node->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        recurse(root);
        return is_sorted(s.begin(),s.end(),[](const int a, const int b){
            return a <= b;
        });
    }
};