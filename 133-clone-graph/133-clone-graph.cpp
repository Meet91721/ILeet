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
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        Node* root = new Node();
        root->val = node->val;
        map<Node*, Node*> mp;
        mp[node] = root;
        queue<pair<Node*,Node*>>q;
        q.push({node,root});
        while(q.size()){
            auto [temp,curr] = q.front();
            q.pop();
            for(int i = 0; i < temp->neighbors.size(); i++){
                if(mp.find(temp->neighbors[i])!=mp.end()){
                    curr->neighbors.push_back(mp[temp->neighbors[i]]);
                    continue;
                }
                Node* tt = new Node();
                tt->val = temp->neighbors[i]->val;
                mp[temp->neighbors[i]] = tt;
                q.push({temp->neighbors[i],tt});
                curr->neighbors.push_back(mp[temp->neighbors[i]]);
            }
        }
        return root;
    }
};