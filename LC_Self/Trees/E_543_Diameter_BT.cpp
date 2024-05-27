/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/diameter-of-binary-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=bkxqA8Rfv04
*/


/*

A. DFS Approach

1. Use the dfs logic to get height of subtrees.
2. Diameter = Height of L-subtree + Height of R-Subtree
3. Height itself is calculated as 1 + max of Height of L-subtree and Height of R-subtree.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomTree.h"

using namespace std;

int dfs(CustomTree::TreeNode* node, int& dia) {
    if (node == nullptr)
        return 0;

    int left = dfs(node->left, dia);
    int right = dfs(node->right, dia);

    dia = max(dia, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(CustomTree::TreeNode* root) {
    int dia = 0;
    dfs(root, dia);
    return dia;
} 


int main() {

    vector<string> nodes = {"1","2","3","4","5"};
    // vector<string> nodes = {"1","2"};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    cout << diameterOfBinaryTree(root) << "\n";

    return 0;
}