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

void addCycle(ListNode** head, int pos) {
    ListNode* temp = *head;
    ListNode* ptr;
    ListNode* last;

    if (pos == -1)
        return;

    int count = 0;
    while (temp != NULL) {
        if (count == pos)
            ptr = temp;
        if (temp->next == NULL) {
            temp->next = ptr;
            break;
        }
        temp = temp->next;
        count++;
    }
}

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {

    vector<int> nums = {3,2,0,-4};  int pos = 1;
    // vector<int> nums = {1,2};  int pos = 0;
    // vector<int> nums = {1};  int pos = -1;

    ListNode* head = createLL(nums);
    addCycle(&head,pos);
    // printList(head);
    
    bool flag = hasCycle(head);
    cout << flag << "\n";

    return 0;
}