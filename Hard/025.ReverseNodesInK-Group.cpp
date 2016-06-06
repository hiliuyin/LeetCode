/*Question:
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Tags:List Linked
*/

/*思路：
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1)
            return head;
            
        ListNode dummyNode(0);
        ListNode* pPre = &dummyNode;
        ListNode* pBeg = head;
        pPre->next = head;   //处理k大于链表长度的情况
        
        while (pBeg != nullptr) 
        {
            ListNode* pEnd = pBeg;
            for (int i = 1; i < k && pEnd != nullptr; ++i)
                pEnd = pEnd->next;
            if (pEnd == nullptr)
                return dummyNode.next;

            pPre->next = pEnd;

            //Reverse k nodes in list
            pEnd = pEnd->next;
            ListNode* p1 = pBeg;
            ListNode* pCur = pBeg->next;
            while (pCur != pEnd)
            {
                ListNode* pNext = pCur->next;
                pCur->next = p1;
                p1 = pCur;
                pCur = pNext;
            }
            pBeg->next = pEnd;
            pPre = pBeg;
            pBeg = pEnd;
        }
        return dummyNode.next;
    }
};
