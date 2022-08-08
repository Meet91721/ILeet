/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     intt val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(intt x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(intt x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define intt long long
class Solution {
public:
    
    // vector<intt>low{4000, INT_MAX/2};
    // vector<intt>high{4000, INT_MIN/2};
    
    
    void dfs(TreeNode* node, intt depth, intt num, vector<intt>&low, vector<intt>&high){
        if(node == NULL)
            return;
        
        if(low[depth]==-1){
            low[depth] = num;
        }
        else
            low[depth] = min(low[depth], num);
        if(high[depth] == -1)
            high[depth] = num;
        else
            high[depth] = max(high[depth], num);
        dfs(node->left,depth+1,(num-low[depth])*2, low, high);
        dfs(node->right,depth+1,(num-low[depth])*2+1, low, high);
    }
    
    intt widthOfBinaryTree(TreeNode* root) {
        vector<intt>low(4000,  -1);
        vector<intt>high(4000, -1);
        dfs(root,0,0, low, high);
        intt res = 0;
        for(intt i = 0; i < 3500; i++){
            res = max(high[i]-low[i]+1, res);
        }
            
        return res;
    }
};