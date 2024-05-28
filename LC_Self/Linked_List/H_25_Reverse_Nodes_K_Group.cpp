/*

Type: Linked List, Recursion

Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
Solution(s): 
- https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/4844525/best-c-solution-optimized-approach-with-explanation-striver-solution/
- https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/

YouTube
NC - https://www.youtube.com/watch?v=1UOPsfP85V4
Striver - https://www.youtube.com/watch?v=lIar1skcQYI

*/

/*

A. Optimal Approach

Time Complexity: O(N) = O(N) + O(N)
Space Complexity: O(1)

0. Iterate over LL.
1. Get Kth node.
2. If Kth node is NULL, means there are not sufficient nodes in group, which will be last group/
    3. If previous node is not NULL, then connect the last group with the previous group.
    4. Break the loop.

5. Store the next node of the last node of the group.
6. Break off the current group from LL by setting next to NULL.

7. Reverse the current group.

8. If current group is first group, set the head to the kth node, which is now the leftmost or first node of the group.
9. Else, connect previous reversed group with current reversed group by setting next of previous group to kth node of current group.

10. Set prev to current group's last node (which was first node before reversing).
11. Set temp to next of current group's original last node which points to next group's first node. (Stored in Step 5).
*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

CustomLL::ListNode* getKthNode(CustomLL::ListNode* head, int k) {
    CustomLL::ListNode* temp = head;
    k -= 1;
    while (temp != NULL && k > 0) {
        temp = temp->next;
        k--;
    }
    return temp;
}

CustomLL::ListNode* reverseLL(CustomLL::ListNode* head) {
    CustomLL::ListNode* curr = head;
    CustomLL::ListNode* prev = NULL;
    CustomLL::ListNode* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

CustomLL::ListNode* reverseKGroup(CustomLL::ListNode* head, int k) {
    CustomLL cll;
    CustomLL::ListNode* temp = head;
    CustomLL::ListNode* prev = NULL;
    CustomLL::ListNode* dummy = new CustomLL::ListNode();
    dummy->next = head;

    while (temp != NULL) {
        CustomLL::ListNode* kth = getKthNode(temp, k);

        if (kth == NULL) {
            if (prev)
                prev->next = temp;
            break;
        }

        CustomLL::ListNode* next = kth->next;
        kth->next = NULL;
        
        kth = reverseLL(temp);

        if (temp == head)
            // head = kth;
            dummy->next = kth;
        else
            prev->next = kth;

       prev = temp;
       temp = next; 
    }

    // return head;
    return dummy->next;
}


int main() {

    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    // int k = 3;

    CustomLL cll;
    CustomLL::ListNode* head = cll.createLL(nums);
    cll.printList(head);
    CustomLL::ListNode* result = reverseKGroup(head, k);
    cll.printList(result);

    return 0;
}