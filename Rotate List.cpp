/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tmpNode, *lastNode;
        int size = 0;
        int cnt = 0;
        
        if (!head)
            return NULL;

        tmpNode = lastNode = head;            
            
        while (tmpNode->next) {
            tmpNode = tmpNode->next;
            size++;
        }
        //tmpNode points to the last node now. (size + 1) is the LL size
        size += 1; 
        k = k % size;
        if (k == 0) {
            return head;
        }
        tmpNode->next = head;
        
        //needs to move foward (size - k - 1) steps to find the boundary
        while(cnt < (size - k - 1)) {
            lastNode = lastNode->next;
            cnt++;
        }
        tmpNode = lastNode->next;
        lastNode->next = NULL;
        return tmpNode;
        
    }
};