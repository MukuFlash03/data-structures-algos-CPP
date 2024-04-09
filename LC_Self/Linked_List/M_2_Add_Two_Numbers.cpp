/*

Type: Linked List, Two Pointers, Dummy Node

Problem: https://leetcode.com/problems/add-two-numbers/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=wgFPrzTjm7s

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

CustomLL::ListNode* addTwoNumbers(CustomLL::ListNode* l1, CustomLL::ListNode* l2) {
    int carry = 0, digSum = 0, sum = 0;
    int l1Val, l2Val;

    CustomLL::ListNode* dummy = new CustomLL::ListNode();
    CustomLL::ListNode* head = dummy;
    

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        l1Val = (l1 == nullptr? 0 : l1->val);
        l2Val = (l2 == nullptr? 0 : l2->val);

        sum = l1Val + l2Val + carry;
        carry = sum / 10;
        digSum = sum % 10;

        head->next = new CustomLL::ListNode(digSum);
        head = head->next;
        l1 = l1 != nullptr? l1->next : nullptr;
        l2 = l2 != nullptr? l2->next : nullptr;
    }

    return dummy->next;
}


int main() {

    vector<int> nums1 = {2,4,3};
    vector<int> nums2 = {5,6,4};

    CustomLL cll;
    CustomLL::ListNode* l1 = cll.createLL(nums1);
    CustomLL::ListNode* l2 = cll.createLL(nums2);

    CustomLL::ListNode* sum = addTwoNumbers(l1, l2);
    cll.printList(sum);

    return 0;
}