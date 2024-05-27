/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Solution(s): 
- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solutions/2976231/c-easy-to-understand/

YouTube
https://www.youtube.com/watch?v=VG5w_VVAgH4
*/


/*

A. Recursive Approach

1. If current root node is same as either p or q or is NULL, then return it.
2. Recursive calls for left and right subtrees.
3. If left is NULL, return right and vice versa.
4. Else return current root node.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include "CustomTree.h"

using namespace std;

CustomTree::TreeNode* lowestCommonAncestor(CustomTree::TreeNode* root, CustomTree::TreeNode* p, CustomTree::TreeNode* q) {
    if(root == NULL || root == p || root == q) 
        return root;

    CustomTree::TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    CustomTree::TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) 
        return right;
    else if (right == NULL) 
        return left;
    else 
        return root;
}


int main() {

    vector<string> nodes = {"3","5","1","6","2","0","8","null","null","7","4"};
    // int p = 5, q = 1;
    int p = 5, q = 4;

    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    CustomTree::TreeNode* nodeP = ctree.findNode(root, p);
    CustomTree::TreeNode* nodeQ = ctree.findNode(root, q);
    
    CustomTree::TreeNode* lca = lowestCommonAncestor(root, nodeP, nodeQ);
    cout << "Lowest Common Ancestor of " << p << " and " << q << ": " << (lca ? to_string(lca->val) : "None") << "\n";
    
    // cout << lca->val << "\n";

    return 0;
}