/*

Type: Linked List, Two Pointers, Dummy Node

Problem: https://leetcode.com/problems/merge-two-sorted-lists/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=XIdigk956u0

*/

/*

A. Basic Approach

- While both lists are not empty,
    - Compare elements of both lists to get smaller element
    - Add this to result LL.

- Check which LL is non-empty and connect it to end of result LL.


// else if (list2->val < list1->val)  -> gave Segmentation fault on not including "=" case


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

CustomLL::ListNode* mergeTwoLists(CustomLL::ListNode* list1, CustomLL::ListNode* list2) {

    CustomLL cll;
    CustomLL::ListNode* dummy = new CustomLL::ListNode();
    //CustomLL::ListNode* result = new CustomLL::ListNode();
    CustomLL::ListNode* result = dummy;

    while (cll.notEmptyList(list1) && cll.notEmptyList(list2)) {
        if (list1->val < list2->val) {
            result->next = list1;
            list1 = list1->next;
        }
        else {
            result->next = list2;
            list2 = list2->next;
        }
        result = result->next;
    }

    if (cll.notEmptyList(list1))
        result->next = list1;
    else if (cll.notEmptyList(list2))
        result->next = list2;

    return dummy->next;
}


int main() {
    vector<int> list1 = {1,2,4};
    vector<int> list2 = {1,3,4};

    CustomLL cll;
    CustomLL::ListNode* head1 = cll.createLL(list1);
    CustomLL::ListNode* head2 = cll.createLL(list2);
    CustomLL::ListNode* mergedHead = mergeTwoLists(head1,head2);
    cll.printList(mergedHead);

    return 0;
}