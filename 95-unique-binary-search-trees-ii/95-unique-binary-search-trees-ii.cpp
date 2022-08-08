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
    vector<int>v;
    vector<TreeNode*> funcc(int l, int r){
        if(l > r)
            return {NULL};
        vector<TreeNode*> ret;
        for(int i = l ; i <= r; i++){
            //current node will be l
            auto v1 = funcc(l,i-1);
            auto v2 = funcc(i+1,r);
            for(int a = 0; a < v1.size(); a++){
                for(int b = 0; b < v2.size(); b++){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = v1[a];
                    curr->right= v2[b];
                    ret.push_back(curr);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return funcc(1, n);
        for(int i = 1; i < n+1; i++)
            v.push_back(i);
        
    }
};