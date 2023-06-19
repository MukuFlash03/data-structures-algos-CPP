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

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertNode(ListNode** head, int item)
{
	ListNode* temp = new ListNode(item);
	ListNode* ptr;

	if (*head == NULL)
		*head = temp;
	else {
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

ListNode* createLL(vector<int> nums) {
    ListNode* head = NULL;
	for (const auto& elem : nums)
		insertNode(&head, elem);
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << '\n';
}

bool notEmptyList(ListNode* head) {
    return head != nullptr;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* dummy = new ListNode();
    ListNode* result = dummy;

    while (notEmptyList(list1) && notEmptyList(list2)) {
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

    if (notEmptyList(list1))
        result->next = list1;
    else if (notEmptyList(list2))
        result->next = list2;

    return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {

    if (lists.empty() || lists.size() == 0)
        return NULL;

    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();

    while (lists.size() > 1) {
        vector<ListNode*> mergedLists;

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

    vector<ListNode*> lists;

    for (const auto& num : nums) {
        ListNode* head = createLL(num);
        lists.push_back(head);
    }
    ListNode* mergedHead = mergeKLists(lists);
    printList(mergedHead);

    return 0;
}