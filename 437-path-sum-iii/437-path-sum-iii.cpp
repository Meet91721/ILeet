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
    vector<int>prefix;
    int funcc(TreeNode* node, int tgt){
        if(node == NULL)
            return 0;
        prefix.push_back(node->val);
        int t = 0;
        int i = prefix.size()-1;
        long int s = 0;
        // if(s==tgt)
        //     t=1;
        while(i >= 0){
            s+=prefix[i];
            if(s == tgt)
                t++;
            i--;
        }
        t+=funcc(node->left,tgt) + funcc(node->right,tgt);
        prefix.pop_back();
        return t;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        return funcc(root,targetSum);
    }
};