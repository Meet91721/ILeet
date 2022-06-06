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
class FindElements {
public:
    
    unordered_set<int>s;
    FindElements(TreeNode* root) {
        root->val = 0;
        repairTree(root);
        s.insert(0);
    }
    
    void repairTree(TreeNode* node){
        
        if(node == NULL)
            return;
        if(node->left != NULL){
            node->left->val = 1+2*node->val;
            s.insert(1+2*node->val);
            repairTree(node->left);
        }
        if(node->right != NULL){
            s.insert(2+2*node->val);
            node->right->val = 2+2*node->val;
            repairTree(node->right);
        }
    }
    
    bool find(int target) {
        if(s.find(target) == s.end())
            return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */