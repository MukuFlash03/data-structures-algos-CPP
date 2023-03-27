LN* temp = new LN();
LN* merge = temp;

while (l1 != NULL && l2 != NULL)
{
    if (l1->val < l2->val)
    {
        temp->next = l1;
        l1 = l1->next;
    }
    else
    {
        temp->next = l2;
        l2 = l2->next;
    }

    temp = temp->next;
}


if (l1 != NULL)
    temp->next = l1;
    
if (l2 != NULL)
    temp->next = l2;

return merge->next;