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
    int pairSum(ListNode* head) {
        
        ListNode*fast = head,*slow = head;

        fast = fast->next->next;
        if(fast == NULL)
            return slow->val + slow->next->val;

        while(fast != NULL && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* p = NULL,*curr = slow->next;

        while(curr != NULL){
            ListNode* n = curr->next;
            curr->next = p;
            p = curr;
            curr = n;
        }
        slow ->next = p;
        int ans = 0;

        while(p != NULL){
            ans = max(ans,head->val + p->val);
            head = head->next;
            p = p->next;
        }

        return ans;
    }
};