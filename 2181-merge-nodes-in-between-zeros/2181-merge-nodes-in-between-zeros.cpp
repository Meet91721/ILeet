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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = NULL;
        ListNode* res;
        int temp = 0;
        while(head!=NULL){
            if(head->val==0){
                if(temp)
                {
                    if(node!=NULL)
                    {
                        // ListNode* tNode = new Node(temp);
                        node->next = new ListNode(temp);
                        node = node->next;
                        temp=0;
                    }
                    else{
                        node = new ListNode(temp);
                        temp = 0;
                        res = node;
                    }
                }
            }
            else{
                temp+=head->val;
            }
            head = head->next;
        }
        return res;
    }
};