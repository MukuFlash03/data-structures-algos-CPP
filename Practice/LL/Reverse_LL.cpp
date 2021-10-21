LN* prev = NULL;
LN* next = NULL;
LN* curr = head;

while (curr != NULL)
{
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
head = prev;