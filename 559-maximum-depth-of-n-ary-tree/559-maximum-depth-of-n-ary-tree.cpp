/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    int DFS(Node* n){
        if(n == NULL){
            return 0;
        }
        int s = (n->children).size();
        if(s == 0)
            return 1;
        int mmax = -1;
        for(int i = 0; i < s; i++){
            int temp = DFS(n->children[i]);
            if(temp>mmax){
                mmax = temp;
            }
        }
        return mmax + 1;
    }
    
    int maxDepth(Node* root) {
        return DFS(root);
    }
};