/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* funcc(Node* node, unordered_map<int,Node*>& mp){
        // cout << node->val;
        vector<Node*> neighbour;
        Node* duplicateNode = new Node(node->val);
        mp[node->val] = duplicateNode;
        for(auto it: node->neighbors){
            if(mp.find(it->val)!=mp.end()){
                neighbour.emplace_back(mp[it->val]);
            }
            else{
                neighbour.emplace_back(funcc(it, mp));
            }
        }
        duplicateNode->neighbors = neighbour;
        return duplicateNode;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<int,Node*> mp;
        return funcc(node, mp);
    }
};