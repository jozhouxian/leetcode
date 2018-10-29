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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head, *pre;
        int k = n, count = 0;
        while (k > 0){
            p = p->next;
            ++count;
            --k;
        }
        while (p != NULL){
            pre = q;
            p = p->next;
            q = q->next;
            count++;
        }
        if(n == count){
            head = head->next;
            free(q);
        } else{
            pre->next = q->next;
            free(q);
        }
        return head;       
    }
};
