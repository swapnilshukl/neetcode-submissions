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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;

        ListNode* curr = head;

        while(curr!=NULL){
            len++;
            curr = curr -> next;
        }
        ListNode dummy(0, head);
        curr = &dummy;
        
        for(int i=0; i<len-n; i++){
            curr = curr -> next;
        }
        ListNode* del = curr->next;
        curr->next = curr->next->next;
        free(del);
        return dummy.next;
    }
};
