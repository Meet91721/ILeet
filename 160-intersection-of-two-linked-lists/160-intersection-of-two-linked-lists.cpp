/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        if(p1 == NULL || p2 == NULL)
            return NULL;
        while(p1!=p2){
            // cout << p1->val << " " << p2->val << '\n';
            if(p1 != NULL)  p1 = p1->next;
            else            p1 = headB;
            if(p2 != NULL)  p2 = p2->next;
            else            p2 = headA;
        }
        return p1;
    }
};