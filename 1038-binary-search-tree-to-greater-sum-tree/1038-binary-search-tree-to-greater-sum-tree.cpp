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
    
    vector<int>sorted_array;
    vector<int>precompute;
    
    void inorder(TreeNode* node){
        if(node == NULL){
            return;
        }
        inorder(node->right);
        sorted_array.push_back(node->val);
        inorder(node->left);
    }
    
    void funcc(TreeNode* node){
        if(node == NULL){
            return;
        }
        auto it = find(sorted_array.begin(), sorted_array.end(), node->val);
        node->val = precompute[it - sorted_array.begin()];
        
        funcc(node->right);
        funcc(node->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        precompute.push_back(sorted_array[0]);
        for(int i = 1; i < sorted_array.size(); i++){
            precompute.push_back(precompute[i-1]+sorted_array[i]);
        }
        funcc(root);
        return root;
    }
};