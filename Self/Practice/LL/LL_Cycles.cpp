LN* slow = head;
LN* fast = head;

while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
        return true;
}
return false;

// Same logic for Middle Node