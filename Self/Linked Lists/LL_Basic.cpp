#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;



struct Node {
    int data;
    Node* next;
};

//1 Node* head; //1 

void InsertNodeAtStart(Node** head, int x) { //3
//2 Node* InsertNodeAtStart(Node* head, int x) { //2
//1 void InsertNodeAtStart(int x) { //1 
    Node* temp = new Node();
    // Node* temp = (Node*)malloc(sizeof(struct Node));

    temp -> data = x;
    //1,2 temp -> next = head;  //1,2   // if (head != NULL)    temp -> next = head;
    //1,2 head = temp; //1,2 

    temp -> next = *head; //3 
    *head = temp; //3 

    //2 return head;
}

Node* InsertNodeAtPosition(Node* head, int x, int n) {
    Node* temp = new Node();
    Node* temp2 = head;

    temp -> data = x;

    // If n = 1, insertion at beginning is to be done
    if (n == 1) {
        temp -> next = head;
        head = temp;
        return head;
    }

}

void PrintList(Node* head) { //2 
//1 void PrintList() { //1 
    //1 Node* temp = head; //1 
    
    /*1
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    */

    ///*2,3
    while (head != NULL) {
        cout << head -> data << ' ';
        head = head -> next;
    }
    //*/

    cout << '\n';
}

int main() {
    //1 head = NULL; //1 
    Node* head = NULL; //2,3

    int n, i, x, pos;
    cout << "How many numbers to be stored: \n";
    cin >> n;

    // printf("How many numbers to be stored: \n");
    // scanf("%d", &n);

    for (i = 0; i < n; i++) {
        cout << "Enter number and position to be stored: \n";
        cin >> x >> pos;
        
        //1 InsertNodeAtStart(x); //1
        //1 PrintList(); //1

        //2 head = InsertNodeAtStart(head, x);  //2
        //3 InsertNodeAtStart(&head, x); //3

        head = InsertNodeAtPosition(head, x, pos);
        PrintList(head); //2,3
        
    }

}
