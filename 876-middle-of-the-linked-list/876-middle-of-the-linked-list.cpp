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
    ListNode* middleNode(ListNode* head) {
        ListNode* one = head;
        ListNode* two = head;
        while(one->next != NULL){
            one = one->next;
            if(one->next != NULL){
                one = one->next;
                two = two-> next;
                continue;
            }
            two=two->next;
            break;
        }
        return two;
    }
};