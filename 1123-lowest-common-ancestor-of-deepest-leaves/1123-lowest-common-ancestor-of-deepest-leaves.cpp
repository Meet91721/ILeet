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
    int depth = 0;
    int cnt = 0;
    void findMaxDepth(TreeNode* node, int sum=0){
        if(node == NULL){
            if(depth<sum){
                // cout << "Changes: " << depth << " to " << sum << '\n';
                cnt=1;
            }
            if(depth==sum){
                // cout << depth << '\n';
                cnt++;
            }
                // cnt++;
            depth = max(depth, sum);
            return;
        }
        findMaxDepth(node->left, sum+1);
        findMaxDepth(node->right, sum+1);
        return;
    }
    TreeNode* res = NULL;
    vector<TreeNode*> dfs(TreeNode* node, int d){
        if(node == NULL)
            return {};
        if(d==depth){
            // cout << node->val << '\n';
            if(cnt==1){
                res=node;
                return {};
            }
            return {node};
        }
        vector<TreeNode*> v1 = dfs(node->left, d+1);
        vector<TreeNode*> v2 = dfs(node->right, d+1);
        for(int i = 0; i < v2.size(); i++){
            v1.emplace_back(v2[i]);
        }
        if(v1.size() == cnt){
            res=node;
            return {};
        }
        return v1;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        findMaxDepth(root);
        cnt/=2;
        dfs(root,1);
        return res;
    }
};