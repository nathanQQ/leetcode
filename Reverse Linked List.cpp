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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        
        ListNode* pre = head;
        ListNode* p = head->next;
        ListNode* post = p->next;
        head->next = NULL;
        while (p) {
            p->next = pre;
            pre = p;
            p = post;
            if (p)
                post = post->next;
        }
        return pre;
    }
};