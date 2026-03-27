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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)
            return head;
        
        ListNode* d = head;
        int n = 1;

        while(d->next != nullptr){
            d = d->next;
            n++;
        }

        k %= n;

        if(k == 0)
            return head;
        
        ListNode* curr = head;

        for(int i=0;i<n-k-1;i++){
            curr = curr->next;
        }

        ListNode* h = curr->next;
        curr->next = nullptr;
        d->next = head;

        return h;
    }
};