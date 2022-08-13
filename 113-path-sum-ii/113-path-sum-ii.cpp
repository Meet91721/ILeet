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
    
    vector<vector<int>> res;
    
    void funcc(TreeNode* node, int tgt, int s, vector<int>&temp){
        if(node == NULL){
            // if(s == tgt)
            //     res.push_back(temp);
            return;
        }
        temp.push_back(node->val);
        s+=node->val;
        if(s == tgt){
            if(node->left == NULL && node->right == NULL){
                res.push_back(temp);
                temp.pop_back();
                return;
            }
        }
        funcc(node->right, tgt, s, temp);
        funcc(node->left, tgt, s, temp);
        temp.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        funcc(root,targetSum,0,v);
        return res;
    }
};