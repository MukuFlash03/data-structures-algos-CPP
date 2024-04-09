/*

Type: Linked List, Two Pointers, Floyd's Algo

//1 -> Global Node used; Not passed as function parameter
//2 -> Node* head passed as function parameter
//3 -> Node** head passed as function parameter, i.e. pointer to Node

Problem: https://leetcode.com/problems/middle-of-the-linked-list/description/
Solution(s): 

*/

/*

A. Optimal Approach

- Use two pointers: slow and fast
    - Fast pointer completes at least one full loop of cycle starting from cycle start point.
    - It overtakes slow pointer once completely.
    - Then starting from 2nd cycle onwards, it may intersect with slow pointer or take more cycles.
- Keep iterating till fast pointer and its next pointer are not null
    - Slow increments by 1; Fast increments by 2
    - If slow matches fast, return true
- Return false if control reaches outside loop


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

CustomLL::ListNode* middleNode(CustomLL::ListNode* head) {
    CustomLL::ListNode* slow = head;
    CustomLL::ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {

    // vector<int> nums = {1,2,3,4,5};
    vector<int> nums = {1,2,3,4,5,6};

    CustomLL cll;
    CustomLL::ListNode* head = cll.createLL(nums);
    CustomLL::ListNode* middle = middleNode(head);
    
    cout << middle->val << "\n";

    return 0;
}