#include "CustomLL.h"

using namespace std;

// --------------------------------------------------------
// Single Linked List
// --------------------------------------------------------

void CustomLL::insertNode(ListNode** head, int item) {
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

CustomLL::ListNode* CustomLL::createLL(vector<int> nums) {
    ListNode* head = NULL;
	for (const auto& elem : nums)
		insertNode(&head, elem);
    return head;
}

void CustomLL::printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << '\n';
}

bool CustomLL::notEmptyList(ListNode* head) {
    return head != nullptr;
}

void CustomLL::addCycle(ListNode** head, int pos) {
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

vector<int> CustomLL::getListFromLL(ListNode* head) {
    ListNode* temp = head;
    vector<int> listArr;
    while (temp != NULL) {
        listArr.push_back(temp->val);
        temp = temp->next;
    }
    return listArr;
}

// --------------------------------------------------------
// Double Linked List
// --------------------------------------------------------

// https://www.programiz.com/dsa/doubly-linked-list

void insertNodeAtStart(CustomLL::DoubleListNode** head, int item) {
    CustomLL::DoubleListNode* temp = new CustomLL::DoubleListNode(item);

    if (*head == NULL) {
        *head = temp;
        return;
    }

    temp->next = *head;
    temp->prev = NULL;
    (*head)->prev = temp;
    *head = temp;
}

void insertNodeAtEnd(CustomLL::DoubleListNode** head, int item) {
    CustomLL::DoubleListNode* temp = new CustomLL::DoubleListNode(item);
    CustomLL::DoubleListNode* ptr;

    if (*head == NULL)
        *head = temp;
    else {
        ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void insertNodeInMiddle(CustomLL::DoubleListNode* prevNode, int item) {
    CustomLL::DoubleListNode* temp = new CustomLL::DoubleListNode(item);

    if (prevNode == NULL) {
        int x = rand() % 2 + 1;
        if (x == 1)
            insertNodeAtStart(&prevNode, item);
        else
            insertNodeAtEnd(&prevNode, item);
    }

    temp->next = prevNode->next;
    temp->prev = prevNode;
    prevNode->next = temp;

    if (temp->next != NULL)
        temp->next->prev = temp;
}

void deleteNodeAtStart(CustomLL::DoubleListNode** head) {
    if (*head == NULL)
        return;

    CustomLL::DoubleListNode* temp = *head;
    *head = (*head)->next;
}

void deleteNodeAtEnd(CustomLL::DoubleListNode** head) {
    if (*head == NULL)
        return;

    CustomLL::DoubleListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    
    if (temp->prev == NULL)
        *head = NULL;
    else
        temp->prev->next = NULL;
}

void deleteNodeInMiddle(CustomLL::DoubleListNode* delNode) {
    if (delNode == NULL)
        return;

    if (delNode->prev == NULL) {
        deleteNodeAtStart(&delNode);
        return;
    }

    if (delNode->next == NULL) {
        deleteNodeAtEnd(&delNode);
        return;
    }

    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
}

CustomLL::DoubleListNode* createLL(vector<int> nums, int size) {
    CustomLL::DoubleListNode* head = NULL;
    for (const auto& elem : nums)
        insertNodeAtEnd(&head, elem);
    return head;
}

void printList(CustomLL::DoubleListNode* head) {
    CustomLL::CustomLL::DoubleListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

bool notEmptyList(CustomLL::DoubleListNode* head) {
    return head != nullptr;
}