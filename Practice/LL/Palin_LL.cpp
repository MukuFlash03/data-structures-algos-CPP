if (head == NULL)
    return true;

stack <int> st;
LN* ptr = head;
while (ptr != NULL)
{
    st.push(ptr->val);
    ptr = ptr->next;
}
ptr = head;
while (ptr != NULL)
{
    if (ptr->val != st.top())
        return false;
    st.pop();
    ptr = ptr->next;
}
