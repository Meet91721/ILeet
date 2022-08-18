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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>q, next;
        q.push(root);
        while(q.size()){
            double ans = 0;
            double nodes = q.size();
            while(q.size()){
                TreeNode* curr = q.front();
                q.pop();
                ans+=curr->val;
                if(curr->left!=NULL)
                    next.push(curr->left);
                if(curr->right!=NULL)
                    next.push(curr->right);
            }
            swap(q,next);
            res.push_back(ans/nodes);
        }
        return res;
    }
};