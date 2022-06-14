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
    
    void preorder(TreeNode* node, vector<int>&pre){
        if(node == NULL)
            return;
        preorder(node->left,pre);
        pre.emplace_back(node->val);
        preorder(node->right,pre);
    }
    
    TreeNode* recurse(vector<int>&pre, int l, int r){
        if(l > r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        n->val=pre[mid];
        TreeNode* le = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        TreeNode* ri = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        le = recurse(pre, l,mid-1);
        ri = recurse(pre, mid+1,r);
        n->left = le;
        n->right = ri;
        return n;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>pre;
        preorder(root,pre);
        return recurse(pre,0,pre.size()-1);
    }
};