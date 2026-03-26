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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        

        if(!head || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* lptr = dummy;
        ListNode* curr = head;

        for(int i=0;i<left-1;i++){
            lptr = lptr->next;
            curr = curr->next;
        }

        ListNode* temp = curr;
        ListNode* prev = NULL;

        for(int i=0;i<right-left+1;i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        lptr->next = prev;
        temp->next = curr;

        return dummy->next;
    }
};