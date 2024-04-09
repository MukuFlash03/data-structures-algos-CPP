/*

Type: Linked List, Recursion

Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=1UOPsfP85V4

*/

/*

A. Optimal Approach


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

CustomLL::ListNode* reverseKGroup(CustomLL::ListNode* head, int k) {
    CustomLL cll;
    CustomLL::ListNode* dummy = new CustomLL::ListNode();
    CustomLL::ListNode* result = dummy;

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

    return 0;
}