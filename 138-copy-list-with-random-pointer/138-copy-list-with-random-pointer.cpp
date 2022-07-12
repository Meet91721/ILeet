/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        
        Node* headCopy = new Node(head->val);
        Node* node = head;
        Node* t = headCopy;
        // map<Node*,Node*>mp;
        map<Node*,Node*>realToCopy;
        int index = 1;
        realToCopy[head]=headCopy;
        while(node->next!=NULL){
            Node* temp = new Node(node->next->val);
            realToCopy[node]=t;
            // mp[node->val]=t;
            index++;
            t->next = temp;
            t = temp;
            node=node->next;
        }
        realToCopy[node]=t;
        // mp[node->val]=t;
        t = headCopy;
        realToCopy[NULL]=NULL;
        node = head;
        while(node!=NULL){
            t->random = realToCopy[node->random];
            t=t->next;
            node = node->next;
        }
        return headCopy;
    }
};