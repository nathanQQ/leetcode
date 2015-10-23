/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* headNode;
        ListNode* pNode;
        
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        if (l1->val < l2->val) {
            headNode = l1;
            l1 = l1->next;
        }
        else {
            headNode = l2;
            l2 = l2->next;
        }
        pNode = headNode;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pNode->next = l1;
                l1 = l1->next;
            }
            else {
                pNode->next = l2;
                l2 = l2->next;
            }
            pNode = pNode->next;
        }
        if (!l1) {
            pNode->next = l2;
        }
        else if (!l2) {
            pNode->next = l1;
        }
        return headNode;
    }
};