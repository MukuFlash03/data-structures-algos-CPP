ListNode* temp = new ListNode(0);
temp->next = head;
ListNode* ptr1 = temp;
ListNode* ptr2 = temp;

for (int i = 0; i < n; i++)
    ptr1 = ptr1->next;

while (ptr1 != NULL)
{
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
}

ptr2->next = ptr2->next->next;
return temp->next; //head returned as starting node -> in place linked list modifications