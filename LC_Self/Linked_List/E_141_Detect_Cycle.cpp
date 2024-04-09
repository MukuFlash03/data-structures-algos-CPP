/*

Type: Linked List, Two Pointers, Floyd's Algo

//1 -> Global Node used; Not passed as function parameter
//2 -> Node* head passed as function parameter
//3 -> Node** head passed as function parameter, i.e. pointer to Node

Problem: https://leetcode.com/problems/linked-list-cycle/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=gBTe7lFR3vc

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

B. HashSet Approach

- Use a hashset of Nodes
- If same node is already in hashset, return true as cycle exists.
- Else return false.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomLL.h"

using namespace std;

bool hasCycle(CustomLL::ListNode* head) {
    CustomLL::ListNode* slow = head;
    CustomLL::ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    // vector<int> nums = {3,2,0,-4};  int pos = 1;
    vector<int> nums = {1,2};  int pos = 0;
    // vector<int> nums = {1};  int pos = -1;

    CustomLL cll;
    CustomLL::ListNode* head = cll.createLL(nums);
    cll.addCycle(&head,pos);
    // cll.printList(head);
    
    bool flag = hasCycle(head);
    cout << flag << "\n";

    return 0;
}