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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }else{
                curr->next = l2;
                l2 = l2 -> next;
                curr = curr -> next;
            }
        }
        if(l1){
            curr->next = l1;
        }else if(l2){
            curr->next = l2;
        }
        return dummy->next;
    }
};
