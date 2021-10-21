bool isFBT(TN* root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left && root->right)
        return isFBT(root->left) && isFBT(root->right);
    return false;
}