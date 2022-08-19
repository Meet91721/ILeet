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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q,next;
        q.push(root);
        
        vector<vector<int>> res;
        while(q.size()){
            vector<int>v;
            while(q.size()){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==NULL)
                    continue;
                v.push_back(curr->val);
                if(curr->left!=NULL)
                    next.push(curr->left);
                if(curr->right!=NULL)
                    next.push(curr->right);
            }
            swap(q,next);
            if(v.size())
                res.push_back(v);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};