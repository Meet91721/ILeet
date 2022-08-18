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
    
    vector<vector<int>>res;
    
    void funcc(queue<TreeNode*>currentLevel){
        
        queue<TreeNode*>nextLevel;
        vector<int>vec;
        
        while(currentLevel.size()){
            
            TreeNode* current = currentLevel.front();
            currentLevel.pop();
            
            if(current == NULL)
                continue;
            
            vec.push_back(current->val);
            
            if(current->left)
                nextLevel.push(current->left);
            if(current->right)
                nextLevel.push(current->right);
            
        }
        if(nextLevel.size())
            funcc(nextLevel);
        if(vec.size())
            res.push_back(vec);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        funcc(q);
        return res;
    }
};