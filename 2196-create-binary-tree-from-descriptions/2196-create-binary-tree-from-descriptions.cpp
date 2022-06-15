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
    TreeNode* createBinaryTree(vector<vector<int>>& description){
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>s;
        for(int i = 0; i < description.size(); i++){
            mp[description[i][0]]=new TreeNode(description[i][0]);
            s.insert(description[i][1]);
            mp[description[i][1]]=new TreeNode(description[i][1]);
        }
        int root = -1;
        for(int i = 0; i < description.size(); i++){
            if(s.find(description[i][0])==s.end())
                root = description[i][0];
            if(description[i][2]==1)
                mp[description[i][0]]->left = mp[description[i][1]];
            else
                mp[description[i][0]]->right = mp[description[i][1]];
            
        }
        return mp[root];
    }
};