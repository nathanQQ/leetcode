/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre;
        ListNode* p;

        if (!head)
            return NULL;

        pre = head;
        p = head->next;
        
        while (p) {
            if (p->val == val) {
                ListNode* tmp = p;
                p = p->next;
                pre->next = p;
                delete tmp;
            }
            else {
                pre = pre -> next;
                p = p -> next;
            }
                
        }
        if (head->val == val) {
            ListNode* tmp_head = head->next;
            delete head;
            return tmp_head;
        }
        else
            return head;
    }
};