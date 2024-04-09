#ifndef CUSTOMLL_H
#define CUSTOMLL_H

#include <iostream>
#include <vector>

using namespace std;

class CustomLL {
private:

public:

    // Single Linked List 
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    void insertNode(ListNode** head, int item);
    ListNode* createLL(vector<int> nums);
    void printList(ListNode* head);
    bool notEmptyList(ListNode* head);
    void addCycle(ListNode** head, int pos);
    vector<int> getListFromLL(ListNode* head);

    // Double Linked List
    struct DoubleListNode {
        int val;
        DoubleListNode* next;
        DoubleListNode* prev;
        DoubleListNode() : val(0), next(nullptr), prev(nullptr) {}
        DoubleListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
        DoubleListNode(int x, DoubleListNode* next, DoubleListNode* prev) : val(0), next(next), prev(prev) {}
    };

    void insertNodeAtStart(CustomLL::DoubleListNode** head, int item);
    void insertNodeAtEnd(CustomLL::DoubleListNode** head, int item);
    void insertNodeInMiddle(CustomLL::DoubleListNode* prevNode, int item);
    void deleteNodeAtStart(CustomLL::DoubleListNode** head);
    void deleteNodeAtEnd(CustomLL::DoubleListNode** head);
    void deleteNodeInMiddle(CustomLL::DoubleListNode* delNode);
    DoubleListNode* createLL(vector<int> nums, int size);
    void printList(DoubleListNode* head);
    bool notEmptyList(DoubleListNode* head);


};

#endif