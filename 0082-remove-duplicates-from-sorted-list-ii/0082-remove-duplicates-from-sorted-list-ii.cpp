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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* d = new ListNode(0);
        d->next = head;

        ListNode* p = d;
        ListNode* curr = d->next;

        while(curr != NULL){
            if(curr->next != NULL && curr->val == curr->next->val){
                while(curr->next != NULL && curr->val == curr->next->val){
                    curr = curr->next;
                }
                p->next = curr->next;
            }else{
                p = curr;
            }
            curr = curr->next;
        }

        return d->next;
    }
};