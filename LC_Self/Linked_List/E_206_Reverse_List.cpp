/*

Type: Linked List, Two Pointers, Floyd's Algo

//1 -> Global Node used; Not passed as function parameter
//2 -> Node* head passed as function parameter
//3 -> Node** head passed as function parameter, i.e. pointer to Node

Problem: https://leetcode.com/problems/reverse-linked-list
Solution(s): 
- https://leetcode.com/problems/reverse-linked-list/solutions/803955/c-iterative-vs-recursive-solutions-compared-and-explained-99-time-85-space/
- https://leetcode.com/problems/reverse-linked-list/solutions/2458632/easy-0-ms-100-fully-explained-java-c-python-js-c-python3-recursive-iterative/


Visualization
https://www.linkedin.com/pulse/js-reversing-linked-list-animated-explanations-mike-cronin-7snle
https://dev.to/jacobjzhang/a-visual-guide-to-reversing-a-linked-list-161e

*/

/*

A. Optimal Approach

- Iterate while current node is not null.
    - Store next node.
    - Point current node to previous node.
    - Set previous node as current node.
    - Set curret node as next node.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

CustomLL::ListNode* reverseList(CustomLL::ListNode* head) {
        CustomLL::ListNode* nextNode = NULL;
        CustomLL::ListNode* prevNode = NULL;
        CustomLL::ListNode* currentNode = head;

        while (currentNode) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }

        return prevNode;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {1,2};
    // vector<int> nums = {};

    CustomLL cll;
    CustomLL::ListNode* head = cll.createLL(nums);
    CustomLL::ListNode* reversed = reverseList(head);
    
    cll.printList(reversed);

    return 0;
}