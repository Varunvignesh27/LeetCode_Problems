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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if(head->next == NULL || head->next->next == NULL)
            return {-1 , -1};

        ListNode* p = head;
        ListNode* c = head->next;
        ListNode* n = c->next;

        int i = 2;
        vector<int> ind;

        while(n != NULL){

            if(c->val > p->val && c->val > n->val){
                ind.push_back(i);
            }

            if(c->val < p->val && c->val < n->val){
                ind.push_back(i);
            }

            p = p->next;
            c = c->next;
            n = n->next;
            i++;
        }

        sort(ind.begin(),ind.end());
        int s = ind.size();

        if(s < 2)
            return {-1 , -1};
        
        int mini = INT_MAX;

        for(int i=0;i<s-1;i++)
            mini = min(mini,ind[i+1] - ind[i]);

        return {mini , ind[s-1] - ind[0]};
    }
};