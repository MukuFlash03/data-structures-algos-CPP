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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, digSum = 0, sum = 0;
    int l1Val, l2Val;

    ListNode* dummy = new ListNode();
    ListNode* head = dummy;
    

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        l1Val = (l1 == nullptr? 0 : l1->val);
        l2Val = (l2 == nullptr? 0 : l2->val);

        sum = l1Val + l2Val + carry;
        carry = sum / 10;
        digSum = sum % 10;

        head->next = new ListNode(digSum);
        head = head->next;
        l1 = l1 != nullptr? l1->next : nullptr;
        l2 = l2 != nullptr? l2->next : nullptr;
    }

    return dummy->next;
}


int main() {

    vector<int> nums1 = {2,4,3};
    vector<int> nums2 = {5,6,4};

    ListNode* l1 = createLL(nums1);
    ListNode* l2 = createLL(nums2);

    ListNode* sum = addTwoNumbers(l1, l2);
    printList(sum);

    return 0;
}