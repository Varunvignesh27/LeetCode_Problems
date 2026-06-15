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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int n = 1;

        while(temp->next != nullptr){
            temp = temp->next;
            n++;
        }

        if(n==1)
            return head->next;
        else if(n==2 || n==3){
            head->next = head->next->next;
        }else if(n == 4 || n==5){
            ListNode* curr = head->next;
            curr->next = curr->next->next;
        }else{
            ListNode* curr = head;
            for(int i=0;i<(n/2)-1;i++)
                curr = curr->next;

            curr->next = curr->next->next;
        }

        return head;
    }
};