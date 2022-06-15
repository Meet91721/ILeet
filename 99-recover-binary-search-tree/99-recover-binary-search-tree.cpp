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
    map<int,TreeNode*>mp;
    
    void recurse(TreeNode* node){
        if(node == NULL)
            return;
        recurse(node->left);
        v.push_back(node->val);
        mp[node->val]=node;
        recurse(node->right);
    }
    
    void recoverTree(TreeNode* root) {
        recurse(root);
        int l;
        bool found = false;
        for(int i = 1; i < v.size(); i++){
            if(v[i]<v[i-1] && !found)
            {
                found=true;
                l=i-1;
                continue;
            }
            if(v[i]<v[i-1] && found)
            {
                swap(mp[v[i]]->val,mp[v[l]]->val);
                return;
            }
        }
        swap(mp[v[l+1]]->val,mp[v[l]]->val);
    }
};