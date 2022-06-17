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
    
    //returns 2, 1, 0, -1
    // -1 for NULL
    // 0  for urgent Need
    // 1 Under Survelliance
    // 2 Holds Camera
    
    int res = 0;
    
    int funcc(TreeNode* node){
        if(node == NULL)
            return -1;
        int a = funcc(node->left);
        int b = funcc(node->right);
        
        if(a==0||b==0){
            res++;
            return 2;
        }
        
        if(a==2||b==2)
            return 1;
        
        if(a==-1&&b==-1)
            return 0;
        
        if(a==1||b==1)
            return 0;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(funcc(root)==0)
            res++;
        return res;
    }
};