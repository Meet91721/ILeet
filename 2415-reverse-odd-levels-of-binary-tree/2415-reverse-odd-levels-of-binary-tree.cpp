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
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>nodes;
        bool rev = false;
        while(q.size()){
            int sz = q.size();
            if(rev)
                reverse(nodes.begin(),nodes.end());
            else
                nodes = vector<int>(0);
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node == NULL)
                    continue;
                if(rev){
                    node->val = nodes[i];
                    if(node->left)
                    q.push(node->left);
                    q.push(node->right);
                }
                else{
                    if(node->left!=NULL){
                        nodes.push_back(node->left->val);
                        nodes.push_back(node->right->val);
                        q.push(node->left);
                        q.push(node->right);
                    }
                }
            }
            rev = 1-rev;
        }
        return root;
    }
};