// Soln 1

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        ListNode *temp = new ListNode();
        ListNode *head = temp;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                temp->next = l1;
                l1=l1->next;
            }
            else
            {   temp->next= l2;
                l2=l2->next;
            }
            
            temp = temp->next;
            
        }
        
        if(l1 != NULL)
            temp->next = l1;
            else if(l2 != NULL)
                temp->next = l2;
        
        
        return head->next;
    }
 
};


// Soln 2

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* merge = dummy;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 && l2 && l1->val <= l2->val)
            {
                merge->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else if (l1 && l2 && l1->val >= l2->val)
            {
                merge->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else if (l2)
            {
                merge->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else
            {
                merge->next = new ListNode(l1->val);
                l1 = l1->next;   
            }
            merge = merge->next;
        }
        return dummy->next;
    }
};