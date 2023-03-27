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
        void reorderList(ListNode* head)
        {
            ListNode* fast = head;
            while (fast != NULL && fast->next != NULL)
            {   
                ListNode* curr = head;
                ListNode* last = head;
                while (last != NULL)
                    last = head->next;
                
                head = curr;
                head->next = last;
                head = head->next->next;
                fast = fast->next;
                fast->next = fast->next->next;
            }
        }
};