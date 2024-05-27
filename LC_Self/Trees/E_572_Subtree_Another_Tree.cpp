/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/subtree-of-another-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=E36O5SWp-LE
*/


/*

A. Recursive Approach

Time Complexity: O(A*B)

I. Function for SubTree

1. Identify base conditions:
    - If subtree null
        - Return true
    - If tree null
        - Return false

2. Recursively call function with OR of comparison between both L-subtrees and R-subtrees

II. Function for SameTree

1.  Identity base conditions:
    - If both null  
        - Return true
    - If either null OR both values do not match
        - Return false
2. Recursively call function with AND of comparison between both L-subtrees and R-subtrees

2. For each node, compare if current subtree matches given subtree.
3. If not, continue to next node in original tree.
4. Else, if same tree, then check if sub tree.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomTree.h"

using namespace std;

bool isSameTree(CustomTree::TreeNode* p, CustomTree::TreeNode* q) {
    if (p == nullptr && q == nullptr)
        return true;
    if ( (p == nullptr || q == nullptr) || (p->val != q->val) )
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(CustomTree::TreeNode* root, CustomTree::TreeNode* subRoot) {
    if (subRoot == nullptr)
        return true;
    if (root == nullptr)
        return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
} 

int main() {

    vector<string> nodesA = {"3","4","5","1","2"};
    vector<string> nodesB = {"4","1","2"};

    // vector<string> nodesA = {"3","4","5","1","2","null","null","null","null","0"};
    // vector<string> nodesB = {"4","1","2"};

    CustomTree ctree;
    CustomTree::TreeNode* rootA = ctree.levelOrderCreateTree(nodesA);
    CustomTree::TreeNode* rootB = ctree.levelOrderCreateTree(nodesB);
    cout << isSubtree(rootA, rootB) << "\n";

    return 0;
}