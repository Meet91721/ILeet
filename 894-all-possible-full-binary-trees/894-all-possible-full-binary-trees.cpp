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
    
    unordered_map<int,vector<TreeNode*>>mp;
    
    vector<TreeNode*> recurse(int n){
        if(n == 1){
            TreeNode* node = new TreeNode();
            vector<TreeNode*>v;
            v.push_back(node);
            return v;
        }
        n--;
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        vector<TreeNode*>vec;
        for(int i = 1; i <= n; i+=2){
            vector<TreeNode*> left = recurse(i);
            vector<TreeNode*> right = recurse(n-i);
            for(int j = 0; j < left.size(); j++){
                for(int k = 0; k < right.size(); k++){
                    TreeNode* node = new TreeNode();
                    node->left=left[j];
                    node->right=right[k];
                    vec.emplace_back(node);
                }
            }
        }
        mp[n]=vec;
        return vec;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)
            return {};
        vector<TreeNode*> r = recurse(n);
        // printt(r[0]);
        return recurse(n);
    }
};