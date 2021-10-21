int maxDepth (TN* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);

        if (ld > rd)
            return ld+1;
        else
            return rd+1;
    }
    
}