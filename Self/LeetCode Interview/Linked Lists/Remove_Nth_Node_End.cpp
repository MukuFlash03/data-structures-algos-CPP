/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* hed = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ptr1 = dummy;
        ListNode* ptr2 = dummy;
        
        for (int i = 1; i <= n+1; i++)
            ptr1 = ptr1->next;
        
        while (ptr1 != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr2->next = ptr2->next->next;
        //return hed;
        return dummy->next;
    }
};