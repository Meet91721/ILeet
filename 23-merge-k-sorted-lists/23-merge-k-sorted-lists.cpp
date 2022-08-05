/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> s;
        
        for(int i = 0; i < lists.size(); i++){
            ListNode* node = lists[i];
            while(node != NULL){
                s.insert(node->val);
                node = node->next;
            }
        }
        
        ListNode* head = NULL;
        ListNode* prev = NULL;
        for(auto it: s){
            ListNode* node = new ListNode(it);
            if(prev!=NULL)
                prev->next = node;
            if(head == NULL)
                head = node;
            prev = node;
        }
        return head;
    }
};