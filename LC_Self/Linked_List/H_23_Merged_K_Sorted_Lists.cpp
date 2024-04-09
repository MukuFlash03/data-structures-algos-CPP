/*

Type: Linked List, Two Pointers, Dummy Node, Merge Sort

Problem: https://leetcode.com/problems/merge-k-sorted-lists/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=q5a5OiGbT6Q

*/

/*

A. Optimal Approach

- Essentially applying Merge Sort, taking 2 lists at a time.
- Complexity = O(nlogk)


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

CustomLL::ListNode* mergeKLists(vector<CustomLL::ListNode*>& lists) {

    if (lists.empty() || lists.size() == 0)
        return NULL;

    CustomLL::ListNode* list1 = new CustomLL::ListNode();
    CustomLL::ListNode* list2 = new CustomLL::ListNode();

    while (lists.size() > 1) {
        vector<CustomLL::ListNode*> mergedLists;

        for (int i = 0; i < lists.size(); i += 2) {
            list1 = lists[i];
            if (i+1 < lists.size())
                list2 = lists[i+1];
            else
                list2 = NULL;
            mergedLists.push_back(mergeTwoLists(list1,list2));     
        }

        lists = mergedLists;
    }
    return lists[0];
}


int main() {

    vector<vector<int>> nums = {{1,4,5},{1,3,4},{2,6}};
    // vector<vector<int>> nums = {};
    // vector<vector<int>> nums = {{}};

    CustomLL cll;
    vector<CustomLL::ListNode*> lists;

    for (const auto& num : nums) {
        CustomLL::ListNode* head = cll.createLL(num);
        lists.push_back(head);
    }
    CustomLL::ListNode* mergedHead = mergeKLists(lists);
    cll.printList(mergedHead);

    return 0;
}