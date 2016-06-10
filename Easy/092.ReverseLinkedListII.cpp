/*Question:
92. Reverse Linked List II My Submissions QuestionEditorial Solution
Total Accepted: 73886 Total Submissions: 261569 Difficulty: Medium
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

Tags: Linked List
Similar Problems:206
*/

/*思路:
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || m <= 0 || n <= 0 || m >= n)
            return head;

        ListNode dummyHead(0);
        ListNode* pPre = &dummyHead;
        pPre->next = head;
        ListNode* pEnd = head;
        
        for(int i = 1; i < m && pPre != nullptr; ++i)
        {
            pPre = pPre->next;
            pEnd = pEnd->next;
        }
            
        ListNode* pBeg = pPre;
        if(pBeg->next != nullptr) pBeg = pBeg->next;
        else return head;
        
        for(int i = m; i <= n && pEnd != nullptr; ++i)
            pEnd = pEnd->next;
            
        auto reverseList = [](ListNode* pBeg, ListNode* pEnd)
        {
            ListNode* pPre = pBeg;
            pBeg = pBeg->next;
            while(pBeg != pEnd)
            {
                ListNode* pNext = pBeg->next;
                pBeg->next = pPre;
                pPre = pBeg;
                pBeg = pNext;
            }
            return pPre;
        };
        pPre->next = reverseList(pBeg, pEnd);
        pBeg->next = pEnd;
        
        return dummyHead.next;
    }
};
