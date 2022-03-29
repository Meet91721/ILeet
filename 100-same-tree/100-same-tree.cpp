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
    
    void funcc(TreeNode* node, vector<string> &vec){
        // if(node == NULL){
        //     vec.push_back("NULL");
        //     return;
        // }
        if(node != NULL && node->left == NULL && node->right == NULL){
            vec.push_back(to_string(node->val));
            return;
        }
        if(node == NULL){
            vec.push_back("NULL");
            return;
        }
        
        vec.push_back(to_string(node->val));
        funcc(node->left, vec);
        funcc(node->right, vec);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string>vec1;
        vector<string>vec2;
        funcc(p, vec1);
        funcc(q, vec2);
        for(int i = 0; i < vec1.size(); i++)
            cout << vec1[i] << ' ';
        cout << '\n';
        for(int i = 0; i < vec2.size(); i++)
            cout << vec2[i] << ' ';
        cout << '\n';
        
        if(vec1 == vec2){
            return true;
        }
        return false;
    }
};