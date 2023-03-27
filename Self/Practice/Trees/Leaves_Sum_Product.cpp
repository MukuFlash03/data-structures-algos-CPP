int leafSP (TN* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        sum += root->data;
        prod *= root->data;
    }
    leafSP(root->left);
    leafSP(root->right);

    return sum;//prod
}