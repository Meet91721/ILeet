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
    vector<int> res ;
    int funcc(int height, TreeNode* node, int maxHeight){
        if(node == NULL)
            return 0;
        if(height<=maxHeight){
            int rightH = funcc(height + 1, node->right, maxHeight);
            int leftH = funcc(height+1,node->left,max(maxHeight,rightH+height));
            return 1+max(rightH,leftH);
        }
        res.emplace_back(node->val);
        int rightH = funcc(height+1,node->right,maxHeight);
        int leftH = funcc(height+1,node->left,max(rightH+height,maxHeight));
        return 1+max(rightH,leftH);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        funcc(0,root,-1);
        return res;
    }
};