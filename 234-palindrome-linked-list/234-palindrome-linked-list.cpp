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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == NULL && head -> next == NULL)
            return true;
        
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow = reverseLL(slow->next);
        while(slow){
            if(slow->val != head->val){
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode* reverseLL(ListNode* node){
        if(node == NULL || node->next == NULL){
            return node;
        }
        ListNode* pre = NULL;
        ListNode* nex = node->next;
        while(nex){
            nex = node->next;
            node->next = pre;
            pre = node;
            node = nex;
        }
        return pre;
    }
};