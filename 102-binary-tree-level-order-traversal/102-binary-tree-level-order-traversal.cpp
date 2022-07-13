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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*>q,qtemp;
        q.push(root);
        vector<vector<int>>res;
        // res.push_back(root->val);
        while(q.size()){
            res.push_back({});
            while(q.size()){
                TreeNode* node = q.front();
                res.back().push_back(node->val);
                q.pop();
                if(node->left!=NULL)
                    qtemp.push(node->left);
                if(node->right!=NULL)
                    qtemp.push(node->right);
            }
            swap(q,qtemp);
        }
        return res;
    }
};