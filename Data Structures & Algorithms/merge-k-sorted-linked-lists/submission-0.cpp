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
private:
    struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) {
        // Return true if 'a' has LOWER priority than 'b' (for a min-heap)
        return a->val > b->val; 
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;

        for(int i=0; i<k; i++){
            if(lists[i]!=nullptr)
            minHeap.push(lists[i]);
        }
        while(!minHeap.empty()){
            ListNode* min = minHeap.top();
            minHeap.pop();
            
            curr->next = min;
            curr = curr->next;
            if(min->next!=NULL) minHeap.push(min->next);

        }
        return dummy->next;
    }
};
