bool isBST (TN* root, int &prev)
{
    if (root)
    {
        if (!isBST(root->left,prev))
            return false;
        if (root->data <= prev)
            return false;
        prev = root->data;
        return isBST(root->right,prev);
    }
    return true;
}

bool isBST (TN* root)
{
    int prev = INT_MIN;
    return isBST(root,prev);
}