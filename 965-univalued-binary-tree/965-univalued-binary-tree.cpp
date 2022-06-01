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
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> q,q1;
        q.push(root);
        int value = root->val;
        while(q.size() > 0){
            while(q.size()>0){
                TreeNode* node = q.front();
                q.pop();
                if(node->val == value){
                    
                    if(node->left != NULL){
                        q1.push(node->left);
                    }
                    if(node->right != NULL){
                        q1.push(node->right);
                    }
                }
                else
                    return false;
            }
            swap(q,q1);
        }
        return true;
    }
};