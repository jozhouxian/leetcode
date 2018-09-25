/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *pre;
        int curry = 0, temp = 0;
        while(p1->next != NULL && p2->next != NULL){
            temp = p1->val + p2->val + curry;
            curry = temp / 10;
            p1->val = temp % 10;
            p1 = p1->next;
            p2 = p2->next;    
        }
        p1->next = (p1->next == NULL) ? p2->next : p1->next;
        
        temp = p1->val + p2->val + curry;
        curry = temp / 10;
        p1->val = temp % 10;
        pre = p1;
        p1 = p1->next;

        while(p1 != NULL){
            temp = p1->val + curry;
            curry = temp / 10;
            p1->val = temp % 10;
            pre = p1;
            p1 = p1->next;
        }
        if(curry){
            pre->next = new ListNode(curry);
        }
        return l1;
    }
};