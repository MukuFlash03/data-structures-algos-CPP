/*

Type: Linked List, Two Pointers, Dummy Node

Problem: https://leetcode.com/problems/copy-list-with-random-pointer/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=5Y2EiZST97Y

*/

/*

A. Basic Approach

1. Create a map of Node* to Node*.
2. Traverse the list and create a new list of new nodes.
3. Store the mapping of old node to new node.
4. Traverse the list again and set the next and random pointers of the new list.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include <map>

using namespace std;


struct Node {
    int val;
    Node* next;
    Node* random;
    Node() : val(0), next(nullptr), random(nullptr) {}
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
    Node(int x, Node *next, Node *random) : val(x), next(next), random(random) {}
};

void insertNode(Node** head, int item) {
	Node* temp = new Node(item);
	Node* ptr;

	if (*head == NULL)
		*head = temp;
	else {
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

Node* traverseNode(Node* head, int pos) {
    Node* temp = head;
    while(pos--)
        temp = temp->next;
    return temp;
}

void addRandom(Node** head, vector<string> random) {
    Node* temp = *head;
    int pos = 0;

    while (temp != NULL) {
        if (random[pos] != "null")
            temp->random = traverseNode(*head, stoi(random[pos]));
        temp = temp->next;
        pos++;
    }

    // cout << "Done adding random\n";
}

Node* createLL(vector<int> nums, vector<string> random) {
    Node* head = NULL;
	for (const auto& elem : nums)
		insertNode(&head, elem);
    addRandom(&head, random);
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << '\n';
}

void printList2(Node* result, Node* head) {
    cout << result->val << "\t";
    cout << result->next->val << "\t";
    if (result->random != NULL)
        cout << result->random->val << "\t";
    cout << "\n";
}

bool notEmptyList(Node* head) {
    return head != nullptr;
}

void checkRandomList(Node* head) {
    Node* dummy = new Node();

    dummy->next = head;
    cout << "Checking random node values\n";
    while (dummy->next != NULL) {
        printList2(dummy, head);
        dummy = dummy->next;
    }
}
// Segmentation fault
// map<int, int> createRandomMap(Node* head) {
//     map<int, int> randomMap;
//     int pos = 0;
//     Node* temp = head;

//     while (temp != NULL) {
//         cout << "Adding " << temp->val << " at " << pos << '\n';
//         randomMap[pos] = temp->random->val;
//         temp = temp->next;
//         pos++;
//     }

//     return randomMap;
// }

Node* copyRandomList(Node* head) {
    Node* dummy;
    Node* temp = head;

    map<Node*, Node*> oldNewNodeMap;

    while(temp != NULL) {
        dummy = new Node(temp->val);
        oldNewNodeMap[temp] = dummy;
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL) {
        dummy = oldNewNodeMap[temp];
        dummy->next = oldNewNodeMap[temp->next];
        dummy->random = oldNewNodeMap[temp->random];
        temp = temp->next;
    }

    return oldNewNodeMap[head];
}

int main() {

    vector<int> list = {7,13,11,10,1};
    vector<string> random = {"null","0","4","2","0"};
    // vector<int> list = {1,2};
    // vector<int> list = {3,3,3};

    Node* head = createLL(list, random);
    // printList(head);
    // checkRandomList(head);
    Node* result = copyRandomList(head);

    return 0;
}