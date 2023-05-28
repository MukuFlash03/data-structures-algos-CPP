/*

Type: Linked List, Two Pointers, Floyd's Algo

//1 -> Global Node used; Not passed as function parameter
//2 -> Node* head passed as function parameter
//3 -> Node** head passed as function parameter, i.e. pointer to Node

Problem: https://leetcode.com/problems/reverse-linked-list
Solution(s): 
- https://leetcode.com/problems/reverse-linked-list/solutions/803955/c-iterative-vs-recursive-solutions-compared-and-explained-99-time-85-space/
- https://leetcode.com/problems/reverse-linked-list/solutions/2458632/easy-0-ms-100-fully-explained-java-c-python-js-c-python3-recursive-iterative/

*/

/*

A. Optimal Approach

- Iterate while current node is not null.
    - Store next node.
    - Point current node to previous node.
    - Set previous node as current node.
    - Set curret node as next node.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
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

ListNode* reverseList(ListNode* head) {
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        ListNode* currentNode = head;

        while (currentNode) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }

        return prevNode;
}

int main() {

    vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {1,2};
    // vector<int> nums = {};

    ListNode* head = createLL(nums);
    ListNode* reversed = reverseList(head);
    
    printList(reversed);

    return 0;
}