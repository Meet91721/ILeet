/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    struct TreeNode* res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    bool traversal(TreeNode* node, int t1, int t2){
        
        if(node == NULL)
            return false;
        // cout << node->val << '\n';
        bool b1 = traversal(node->left, t1, t2);
        bool b2 = traversal(node->right, t1, t2);
        
        if((b1 || b2) && (node->val == t1 || node->val == t2)){
            res = node;
            return true;
        }
        if(b1 && b2){
            res = node;
            return true;
        }
        return node->val == t1 ||node->val == t2 || b1 || b2;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traversal(root, p->val, q->val);
        return res;
    }
};