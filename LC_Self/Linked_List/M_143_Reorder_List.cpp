/*

Type: Linked List, Two Pointers, Dummy Node

Problem: https://leetcode.com/problems/reorder-list/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=S5bfdUTrKLM

*/

/*

A. Optimal Approach - Merge 2 Lists Approach

- Consider list to be made up of two parts: 
    - Divide it equally in the middle (Slow + Fast pointers)
    - 1st half tail points to NULL since it is now end of list
    - 1st half goes from L to R
    - 2nd half goes from R to L (Reverse 2nd half of LL)

- Alternate between putting nodes at the end of the head and the end of the tail.
    - Start with two pointers: head and tail.
    - Attach head node followed by tail node.
    - Move both pointers inwards.
    - Repeat.

    - L0 node points to Ln-1    and     Ln-1 node points to L1
    - L1 node points to Ln-2    and     Ln-2 node points to L3 
    - and so on...



B. Extra memory Approach


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

void reorderList(CustomLL::ListNode** head) {
    CustomLL::ListNode* slow = *head;
    CustomLL::ListNode* fast = *head;

    // Divide list into two halves
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse   2nd half
    CustomLL::ListNode* list2 = NULL;
    CustomLL::ListNode* prev = NULL;
    CustomLL::ListNode* temp = NULL;

    list2 = slow->next;
    slow->next = NULL;

    while (list2 != NULL) {
        temp = list2->next;
        list2->next = prev;
        prev = list2;
        list2 = temp;
    }

    // Merge two halves
    CustomLL::ListNode* first = *head;
    CustomLL::ListNode* second = prev;
    CustomLL::ListNode* temp1 = NULL;
    CustomLL::ListNode* temp2 = NULL;

    while (second != NULL) {
        temp1 = first->next;
        temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}


int main() {

    // vector<int> nums = {1,2,3,4};
    vector<int> nums = {1,2,3,4,5};
    
    CustomLL cll;
    CustomLL::ListNode* list = cll.createLL(nums);
    reorderList(&list);
    cll.printList(list);

    return 0;
}