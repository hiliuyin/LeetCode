/*Question:
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/*思路：
分别设pSlow和pFast两个指针，一个指向不重复链表的最后一个节点，另一个指向要处理的节点
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pSlow = head;
        ListNode* pFast = head->next;
        while(pFast != nullptr)
        {
            if(pSlow->val == pFast->val)
            {
                pSlow->next = pFast->next;
                delete pFast;
                pFast = pSlow->next;
            }
            else
            {
                pSlow = pFast;
                pFast = pFast->next;
            }
        }
        
        return head;
    }
};
