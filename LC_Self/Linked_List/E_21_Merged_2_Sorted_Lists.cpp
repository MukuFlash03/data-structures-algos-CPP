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


int main() {

    vector<int> list1 = {1,2,4};
    vector<int> list2 = {1,3,4};

    ListNode* head1 = createLL(list1);
    ListNode* head2 = createLL(list2);
    ListNode* mergedHead = mergeTwoLists(head1,head2);
    printList(mergedHead);

    return 0;
}