/*

Type: Linked List, Two Pointers, Dummy Node

Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Solution(s): 
- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/2757145/c-del-n-th-node-from-the-end/
- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/3251452/c-easiest-code-submitted-ever/
- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/3280915/c-solution/


YouTube
NC - https://www.youtube.com/watch?v=XVuQxVej6y8

*/

/*

A. Optimal Approach

- Have two pointers, where one is k nodes ahead of the other. 
- When the node ahead reaches the end, the other node is k nodes behind.
- However, slow will point to node being removed but it should point to node just before this node.
- Hence, use a dummy node which is attached at the start, before head.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

CustomLL::ListNode* removeNthFromEnd(CustomLL::ListNode** head, int n) {
    
    CustomLL::ListNode* dummy = new CustomLL::ListNode();
    dummy->next = *head;

    CustomLL::ListNode* slow = dummy;
    CustomLL::ListNode* fast = *head;

    while (n--)
        fast = fast->next;

    // while (fast == NULL)
    //     return (*head)->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}


int main() {

    vector<int> nums = {1,2,3,4,5};  int n = 2;
    // vector<int> nums = {1};  int n = 1;
    // vector<int> nums = {1,2};  int n = 1;

    CustomLL cll;
    CustomLL::ListNode* head = cll.createLL(nums);
    CustomLL::ListNode* delHead = removeNthFromEnd(&head,n);
    cll.printList(delHead);

    return 0;
}