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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* nex = head -> next;
        // if(nex == NULL)
        //     return head;
        while(nex){
            // cout << head->val << '\n';
            nex = head->next;
            head->next = pre;
            pre = head;
            head = nex;
        }
        return pre;
    }
};