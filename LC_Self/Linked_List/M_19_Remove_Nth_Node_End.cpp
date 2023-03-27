/*

Type: Linked List, Two Pointers, Dummy Node

Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Solution(s): 
- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/2757145/c-del-n-th-node-from-the-end/
- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/3251452/c-easiest-code-submitted-ever/
- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/3280915/c-solution/


YouTube
NC - https://www.youtube.com/watch?v=XVuQxVej6y8

*/

/*

A. Optimal Approach

- Have two pointers, where one is k nodes ahead of the other. 
- When the node ahead reaches the end, the other node is k nodes behind.
- However, slow will point to node being removed but it should point to node just before this node.
- Hence, use a dummy node which is attached at the start, before head.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

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

ListNode* removeNthFromEnd(ListNode** head, int n) {
    
    ListNode* dummy = new ListNode();
    dummy->next = *head;

    ListNode* slow = dummy;
    ListNode* fast = *head;

    while (n--)
        fast = fast->next;

    while (fast == NULL)
        return (*head)->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}


int main() {

    vector<int> nums = {1,2,3,4,5};  int n = 2;
    // vector<int> nums = {1};  int n = 1;
    // vector<int> nums = {1,2};  int n = 1;

    ListNode* head = createLL(nums);
    ListNode* delHead = removeNthFromEnd(&head,n);
    printList(delHead);

    return 0;
}