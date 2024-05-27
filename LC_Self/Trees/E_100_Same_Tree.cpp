/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/same-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=vRbbcKXCxOw
*/


/*

A. Recursive Depth-first search

1. Identity base conditions:
    - If both null  
        - Return true
    - If either null OR both values do not match
        - Return false
2. Recursively call function with AND of comparison between both L-subtrees and R-subtrees

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

int main() {

    vector<string> nodesA = {"1","2","3"};
    vector<string> nodesB = {"1","2","3"};

    // vector<string> nodesA = {"1","2"};
    // vector<string> nodesB = {"1","null","2"};

    // vector<string> nodesA = {"1","2","1"};
    // vector<string> nodesB = {"1","1","2"};
    
    CustomTree ctree;
    CustomTree::TreeNode* rootA = ctree.levelOrderCreateTree(nodesA);
    CustomTree::TreeNode* rootB = ctree.levelOrderCreateTree(nodesB);
    cout << isSameTree(rootA, rootB) << "\n";

    return 0;
}