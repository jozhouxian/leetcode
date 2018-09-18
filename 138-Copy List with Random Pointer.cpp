/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 /*
 * create new node after each origional node
 * assign random pointer of each new node
 * cut the list into two list and return the new one
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if( head == NULL ){
            return NULL;
        }
        RandomListNode *p2 = NULL, *p1 = head, *pre;
        while( p1!= NULL ) {
            p2 = p1;
            p1 = p1->next;
            p2->next = new RandomListNode(p2->label);
            p2->next->next = p1;
        }
        RandomListNode *newHead = head->next;
        p2 = head;
        p1 = newHead;
        while( p1 != NULL ) {
            p1->random = (p2->random != NULL) ? p2->random->next : NULL;
            p2 = p1->next;
            p1 = p2!=NULL ? p2->next : NULL;
        }
        p2 = head;
        p1 = newHead;
        while( p1 != NULL ) {
            pre = p1;
            p1 = p1->next;
            p2->next = p1;
            p2 = pre;
        }
        return newHead;
    }
};