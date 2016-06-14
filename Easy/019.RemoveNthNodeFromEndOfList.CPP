/*
Given a linked list, remove the nth node from the end of list and return its head.
For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

//Code:
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
        if(head == nullptr || n < 1)
            return head;
            
        ListNode* pFast = head;
        ListNode dummyHead(0);
        ListNode* pPre = &dummyHead;
        pPre->next = head;
        
        for(int i = 0; i < n && pFast != nullptr; ++i)
            pFast = pFast->next;
        
        ListNode* pDelete = head;
        while(pFast != nullptr)
        {
            pDelete = pDelete->next;
            pFast = pFast->next;
            pPre = pPre->next;
        }
        
        pPre->next = pDelete->next;
        delete pDelete;
        return dummyHead.next;
    }
};
