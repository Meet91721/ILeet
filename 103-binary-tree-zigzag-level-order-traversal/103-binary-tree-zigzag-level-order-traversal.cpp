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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*>q,q1;
        q.push(root);
        vector<vector<int>>res;
        bool isReversed = false;
        while(q.size()){
            res.push_back({});
            while(q.size()){
                TreeNode* node = q.front();
                q.pop();
                res.back().push_back(node->val);
                if(node->left){
                    q1.push(node->left);
                }
                if(node->right){
                    q1.push(node->right);
                }
            }
            swap(q,q1);
            if(isReversed){
                reverse(res.back().begin(),res.back().end());
                isReversed = false;
            }
            else
                isReversed=true;
        }
        return res;
    }
};