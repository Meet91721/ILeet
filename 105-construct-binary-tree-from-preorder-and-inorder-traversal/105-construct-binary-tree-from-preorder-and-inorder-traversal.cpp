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
    int index = 0;
    TreeNode* funcc(int i, int j, vector<int> &preorder, vector<int> &inorder){
        // cout << i << " " << j << '\n';
        if(j<i)
            return NULL;
        if(j==i){
            TreeNode* node = new TreeNode(preorder[index]);
            index++;
            return node;
        }
        int x = i;
        for(; x <= j; x++){
            if(inorder[x]==preorder[index])
                break;
        }
        TreeNode* node = new TreeNode(preorder[index]);
        index++;
        node->left = funcc(i,x-1,preorder,inorder);
        node->right = funcc(x+1,j,preorder,inorder);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return funcc(0,preorder.size()-1,preorder,inorder);
    }
};