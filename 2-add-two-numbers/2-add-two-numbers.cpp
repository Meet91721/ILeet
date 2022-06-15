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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head = new ListNode(0);
        ListNode* node=head;
        while(l1&&l2){
            int temp = l1->val+carry+l2->val;
            if(temp>9)
                carry=1;
            else
                carry=0;
            ListNode* n = new ListNode(temp%10);
            l1=l1->next;
            l2=l2->next;
            node->next=n;
            node=n;
        }
        while(l1){
            int temp = carry+l1->val;
            if(temp>9)
                carry=1;
            else
                carry=0;
            ListNode* n = new ListNode(temp%10);
            node->next=n;
            node=n;
            l1=l1->next;
        }
        while(l2){
            int temp = carry+l2->val;
            if(temp>9)
                carry=1;
            else
                carry=0;
            ListNode* n = new ListNode(temp%10);
            node->next=n;
            node=n;
            l2=l2->next;
        }
        if(carry)
        {
            ListNode* n = new ListNode(1);
            node->next = n;
        }
        return head->next;
    }
};