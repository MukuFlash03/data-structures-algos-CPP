/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=gs2LMfuOR9k
*/


/*

A. Recursive Approach

Time Complexity = O(logn) = Height of tree
    - Visiting just one of the nodes on each level

- Set currNode to the root node.
- Keep iterating till currNode is not null.
    - If both p,q are greater than currNode
        - Set currNode to right subtree of currNode
    - Else if both p,q are lower than currNode
        - Set currNode to left subtree of currNode
    - Else break
- Return currNode


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include "CustomTree.h"

using namespace std;

CustomTree::TreeNode* lowestCommonAncestor(CustomTree::TreeNode* root, CustomTree::TreeNode* p, CustomTree::TreeNode* q) {

    CustomTree::TreeNode* currNode = root;

    while (currNode != nullptr) {
        if ( (p->val > currNode->val) && (q->val > currNode->val) )
            currNode = currNode->right;
        else if ( (p->val < currNode->val) && (q->val < currNode->val) )
            currNode = currNode->left;
        else
            break;
    }
    return currNode;
}


int main() {

    vector<string> nodes = {"6","2","8","0","4","7","9","null","null","3","5"};
    int p = 2, q = 8;
    // int p = 2, q = 4;

    // vector<string> nodes = {"2","1"};
    // int p = 2, q = 1;
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    CustomTree::TreeNode* nodeP = ctree.findNode(root, p);
    CustomTree::TreeNode* nodeQ = ctree.findNode(root, q);

    CustomTree::TreeNode* lca = lowestCommonAncestor(root, nodeP, nodeQ);
    cout << lca->val << "\n";

    return 0;
}